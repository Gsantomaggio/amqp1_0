#ifndef AMQP1_0_DECODE_H
#define AMQP1_0_DECODE_H


#include "types.h"
#include <stdlib.h>


size_t parseAmqp10MessageBuffer(char *source_buffer, long len, PMessage_t out_message);

size_t decodeDescribedFormatCode(char *source_buffer, PDescribedFormatCode out_described_format_code);


#endif //AMQP1_0_DECODE_H
