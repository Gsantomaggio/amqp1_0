//
// Created by Gabriele Santomaggio on 19/02/23.
//

#include "amqp_wire_formatting.h"
#include "types.h"
#include <string.h>
#include <stdlib.h>
#include <printf.h>

int read_char(char *source_buffer, char *out_value) {
    int offset = 0;
    memcpy(out_value, source_buffer + offset, sizeof(char));
    return offset + sizeof(char);
}

int read_int(char *source_buffer, uint32_t *out_value) {
    int offset = 0;
    unsigned char tmp[sizeof(uint32_t)];
    memcpy(tmp, source_buffer + offset, sizeof(uint32_t));
    *out_value = (tmp[0] << 24) + (tmp[1] << 16) + (tmp[2] << 8) + tmp[3];
    return offset + sizeof(uint32_t);
}


int read_buffer(char *source_buffer, char *out_value, size_t len) {
    memcpy(out_value, source_buffer, len);
    return len;
}

int read_type(char *source_buffer, char *out_type) {
    return read_char(source_buffer, out_type);
}

int read_application_data(char *source_buffer, PMessage_t message) {
    size_t offset = 0;
    char type;
    offset += read_type(source_buffer, &type);
    switch (type) {
        case FORMAT_CODE_VBIN8: {
            char len;
            offset += read_char(source_buffer + offset, &len);
            message->data = malloc(len);
            offset += read_buffer(source_buffer + offset, message->data, len);
        }
            break;
        case FORMAT_CODE_Vbin32: {
            uint32_t len;
            offset += read_int(source_buffer + offset, &len);
            message->data = malloc(len);
            offset += read_buffer(source_buffer + offset, message->data, len);
        }
            break;
    }
    return offset;

}

