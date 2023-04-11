#ifndef AMQP1_0_DECODE_H
#define AMQP1_0_DECODE_H


#include "types.h"
#include "message.h"
#include <stdlib.h>


size_t read_amqp1_0_from_buffer(const unsigned char *source_buffer, long len, PMessage_t out_message);

size_t decode_described_format_code(const unsigned char *source_buffer, PDescribedFormatCode out_described_format_code);


#endif //AMQP1_0_DECODE_H
