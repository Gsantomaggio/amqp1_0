#ifndef AMQP1_0_DECODE_H
#define AMQP1_0_DECODE_H


#include "types.h"


int parseAmqp10MessageBuffer(char *source_buffer, int len, PMessage_t out_message);

int decodeDescribedFormatCode(char *source_buffer, PDescribedFormatCode out_described_format_code);


#endif //AMQP1_0_DECODE_H
