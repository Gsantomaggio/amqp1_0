//
// Created by Gabriele Santomaggio on 12/03/23.
//

#ifndef AMQP1_0_ENCODE_H
#define AMQP1_0_ENCODE_H
#include "message.h"

void write_amqp1_0_to_buffer(PMessage_t message, unsigned char *buffer);


#endif //AMQP1_0_ENCODE_H
