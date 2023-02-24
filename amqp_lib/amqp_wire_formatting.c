//
// Created by Gabriele Santomaggio on 19/02/23.
//

#include "amqp_wire_formatting.h"
#include <string.h>

int read_char(char *source_buffer, char *out_value) {
    int offset = 0;
    memcpy(out_value, source_buffer + offset, sizeof(char));
    return offset + sizeof(char);
}

int read_buffer(char *source_buffer, char *out_value) {
    int offset = 0;
    char type;
    offset += read_type(source_buffer, &type);
    switch (type) {
        case (char)0xa0: {
            char len;
            offset += read_char(source_buffer + offset, &len);
            offset += read_buffer(source_buffer + offset, out_value);
        }
            break;
    }
    return offset;
}

int read_type(char *source_buffer, char *out_type) {
    return read_char(source_buffer, out_type);
}





