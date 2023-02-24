#include "library.h"
#include "amqp_wire_formatting.h"

#include <stdio.h>


Message_t newMessage() {
    Message_t message;
    return message;
}

DescribedFormatCode decodeDescribedFormatCode(char *source_buffer) {
    DescribedFormatCode result;
    int offset = 0;
    offset += read_char(source_buffer, &result.v1);
    offset += read_char(source_buffer + offset, &result.v2);
    offset += read_char(source_buffer + offset, &result.formatCode);
    result.size = offset;
    return result;
}

Message_t parseMessage(char *source_buffer) {
    DescribedFormatCode formatCode = decodeDescribedFormatCode(source_buffer);
    Message_t message;
    switch (formatCode.formatCode) {
        case APPLICATION_DATA:
            read_buffer(source_buffer, message.data);
            break;
    }
    return message;
}





