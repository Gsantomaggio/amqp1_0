#include "library.h"
#include "amqp_wire_formatting.h"

#include <stdio.h>
#include <types.h>



DescribedFormatCode decodeDescribedFormatCode(char *source_buffer) {
    DescribedFormatCode result;
    int offset = 0;
    offset += read_char(source_buffer, &result.v1);
    offset += read_char(source_buffer + offset, &result.v2);
    offset += read_char(source_buffer + offset, &result.formatCode);
    result.size = offset;
    return result;
}

int parseMessage(char *source_buffer, PMessage_t message) {
    DescribedFormatCode formatCode = decodeDescribedFormatCode(source_buffer);
    int offset = formatCode.size;

    switch (formatCode.formatCode) {
        case APPLICATION_DATA:
            offset += read_application_data(
                    source_buffer + offset,
                    message);
            break;
    }
    return 0;
}





