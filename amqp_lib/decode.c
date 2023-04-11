#include "message.h"
#include "amqp_wire_formatting.h"
#include <types.h>
#include <printf.h>




size_t decode_described_format_code(const unsigned char *source_buffer, PDescribedFormatCode out_described_format_code) {
    size_t offset = 0;
    offset += read_char(source_buffer, &out_described_format_code->v1);
    offset += read_char(source_buffer + offset, &out_described_format_code->v2);
    offset += read_char(source_buffer + offset, &out_described_format_code->formatCode);
    out_described_format_code->size = offset;
    return 0;
}

size_t read_amqp1_0_from_buffer(const unsigned char *source_buffer, long len, PMessage_t out_message) {
    size_t offset = 0;
    if (len < 0) {
        return 1;
    }
    const int max_operations = 1; // the number of fields are supported.
                                  // 1- APPLICATION_DATA

    int current_operation = 0;
    while (offset != len && current_operation < max_operations) {
        DescribedFormatCode formatCode;
        decode_described_format_code(source_buffer, &formatCode);
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