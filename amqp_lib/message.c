//
// Created by Gabriele Santomaggio on 12/03/23.
//

#include "message.h"
#include "amqp_wire_formatting.h"
#include "types.h"
#include <string.h>

Message_t CreateMessage_t(unsigned char *body, size_t body_len) {
    Message_t result;
    malloc_amqp_data(&result, body_len);
    memcpy(result.bodyAmqpData->body, body, body_len);
    result.bodyAmqpData->body_len = body_len;
    return result;
}

size_t described_format_code_size() {
    return sizeof(unsigned char) + sizeof(unsigned char) + sizeof(unsigned char);
}

void free_message_fields(PMessage_t msg) {
    if (msg->bodyAmqpData != NULL) {
        if (msg->bodyAmqpData->body != NULL) {
            free(msg->bodyAmqpData->body);
        }
        free(msg->bodyAmqpData);
    }
}

void malloc_amqp_data(PMessage_t msg, size_t __size) {
    msg->bodyAmqpData = malloc(sizeof(BODY_AMQP_DATA));
    msg->bodyAmqpData->body = malloc(sizeof(unsigned char) * __size);
    msg->bodyAmqpData->body_len = __size;
}

size_t message_size(PMessage_t message) {
    size_t size = described_format_code_size();
    size += sizeof(char); // type Vbin8
    if (message->bodyAmqpData->body_len <= 255) {
        size += sizeof(char); // body_len it is a byte
    } else {
        size += sizeof(int); // body_len it is an int
    }
    size += message->bodyAmqpData->body_len;
    return size;
}

int unmarshal_described_format_code(const unsigned char *source_buffer,
                                    PDescribedFormatCode out_described_format_code) {
    size_t offset = 0;
    offset += read_char(source_buffer, &out_described_format_code->v1);
    offset += read_char(source_buffer + offset, &out_described_format_code->v2);
    offset += read_char(source_buffer + offset, &out_described_format_code->formatCode);
    out_described_format_code->size = offset;
    return 0;
}

int Unmarshal(const unsigned char *source_buffer, size_t len, PMessage_t out_message) {
    size_t offset = 0;
    if (len < 0) {
        return 1;
    }
    const int max_operations = 1; // the number of supported fields.
    // 1- APPLICATION_DATA

    int current_operation = 0;
    while (offset != len && current_operation < max_operations) {
        DescribedFormatCode formatCode;
        unmarshal_described_format_code(source_buffer, &formatCode);
        switch (formatCode.formatCode) {
            case APPLICATION_DATA:
                offset += formatCode.size;
                offset += read_application_data(
                        source_buffer + offset,
                        out_message);
                break;
            default:
                return 1;
        }
        current_operation++;
    }
    return 0;
}

MESSAGE_DATA Marshal(PMessage_t message) {
    size_t buffer_size = message_size(message);
    MESSAGE_DATA result;
    result.payload = malloc(sizeof(unsigned char) * buffer_size);
    result.payload_len = buffer_size;
    DescribedFormatCode describedFormatCode;
    describedFormatCode.formatCode = APPLICATION_DATA;
    describedFormatCode.v1 = 0;
    describedFormatCode.v2 = 0;
    size_t offset = marshal_described_format_code(&describedFormatCode, result.payload);
    if (message->bodyAmqpData->body_len <= 255) {
        offset += write_char(FORMAT_CODE_VBIN8, result.payload + offset);
        offset += write_char((const unsigned char)message->bodyAmqpData->body_len, result.payload + offset);
    } else {
        offset += write_char(FORMAT_CODE_Vbin32, result.payload + offset);
        offset += write_int((const int)message->bodyAmqpData->body_len, result.payload + offset);
    }
    write_chars(message->bodyAmqpData->body, result.payload + offset, message->bodyAmqpData->body_len);
    return result;
}


size_t marshal_described_format_code(PDescribedFormatCode pSourceDescribedFormatCode, unsigned char *destination_char) {
    size_t offset = 0;
    offset += write_pchar(&pSourceDescribedFormatCode->v1, destination_char + offset);
    offset += write_pchar(&pSourceDescribedFormatCode->v2, destination_char + offset);
    offset += write_pchar(&pSourceDescribedFormatCode->formatCode, destination_char + offset);
    return offset;
}


void free_message_data(MESSAGE_DATA message_data) {
    if (message_data.payload != NULL) {
        free(message_data.payload);
        message_data.payload = NULL;
    }

}