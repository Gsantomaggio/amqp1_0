#ifndef AMQP1_0_DECODE_H
#define AMQP1_0_DECODE_H


#include "types.h"
#include <stdlib.h>


size_t parse_amqp10_message_buffer(const unsigned char *source_buffer, long len, PMessage_t out_message);

size_t decodeDescribedFormatCode(const unsigned char *source_buffer, PDescribedFormatCode out_described_format_code);

void freeMessageFields(PMessage_t msg);


#endif //AMQP1_0_DECODE_H
