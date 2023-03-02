#include "decode.h"
#include "amqp_wire_formatting.h"
#include <types.h>


void freeMessageFields(PMessage_t msg) {
    if (msg->bodyAmqpData != NULL) {
        if (msg->bodyAmqpData->body != NULL) {
            free(msg->bodyAmqpData->body);
        }
        free(msg->bodyAmqpData);
    }
}

size_t decodeDescribedFormatCode(unsigned char *source_buffer, PDescribedFormatCode out_described_format_code) {
    size_t offset = 0;
    offset += read_char(source_buffer, &out_described_format_code->v1);
    offset += read_char(source_buffer + offset, &out_described_format_code->v2);
    offset += read_char(source_buffer + offset, &out_described_format_code->formatCode);
    out_described_format_code->size = offset;
    return 0;
}

size_t parse_amqp10_message_buffer(unsigned char *source_buffer, long len, PMessage_t out_message) {
    size_t offset = 0;
    while (offset != len) {
        DescribedFormatCode formatCode;
        decodeDescribedFormatCode(source_buffer, &formatCode);
        switch (formatCode.formatCode) {
            case APPLICATION_DATA:
                offset += formatCode.size;
                offset += read_application_data(
                        source_buffer + offset,
                        out_message);
                break;
        }
    }
    return 0;
}