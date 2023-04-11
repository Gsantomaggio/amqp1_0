//
// Created by Gabriele Santomaggio on 12/03/23.
//

#ifndef AMQP1_0_MESSAGE_H
#define AMQP1_0_MESSAGE_H

#include <stdlib.h>


typedef struct BODY_AMQP_DATA_S {
    unsigned char *body;
    size_t body_len;
} BODY_AMQP_DATA;

typedef struct {
    BODY_AMQP_DATA *bodyAmqpData;
} Message_t, *PMessage_t;


typedef struct {
    unsigned char v1;
    unsigned char v2;
    unsigned char formatCode;
    size_t size;

} DescribedFormatCode, *PDescribedFormatCode;



void free_message_fields(PMessage_t msg);
void malloc_amqp_data(PMessage_t msg, size_t __size);

#endif //AMQP1_0_MESSAGE_H
