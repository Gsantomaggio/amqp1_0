//
// Created by Gabriele Santomaggio on 19/02/23.
//

#include "amqp_wire_formatting.h"
#include "types.h"
#include "message.h"
#include <string.h>

size_t read_char(const unsigned char *source_buffer, unsigned char *out_value) {
    int offset = 0;
    memcpy(out_value, source_buffer + offset, sizeof(char));
    return offset + sizeof(char);
}

size_t read_int(const unsigned char *source_buffer, uint32_t *out_value) {
    unsigned char tmp[sizeof(uint32_t)];
    memcpy(tmp, source_buffer, sizeof(uint32_t));
    *out_value = (tmp[0] << 24) + (tmp[1] << 16) + (tmp[2] << 8) + tmp[3];
    return sizeof(uint32_t);
}

size_t read_buffer(const unsigned char *source_buffer, unsigned char *out_value, size_t len) {
    memcpy(out_value, source_buffer, len);
    return len;
}

size_t read_type(const unsigned char *source_buffer, unsigned char *out_type) {
    return read_char(source_buffer, out_type);
}

size_t read_application_data(const unsigned char *source_buffer, PMessage_t message) {
    size_t offset = 0;
    unsigned char type;
    offset += read_type(source_buffer, &type);
    switch (type) {
        case FORMAT_CODE_VBIN8: {
            unsigned char len;
            offset += read_char(source_buffer + offset, &len);
            malloc_amqp_data(message, len);
            offset += read_buffer(source_buffer + offset, message->bodyAmqpData->body, len);
        }
            break;
        case FORMAT_CODE_Vbin32: {
            uint32_t len;
            offset += read_int(source_buffer + offset, &len);
            malloc_amqp_data(message, len);
            offset += read_buffer(source_buffer + offset, message->bodyAmqpData->body, len);
        }
            break;
    }

    return offset;

}

