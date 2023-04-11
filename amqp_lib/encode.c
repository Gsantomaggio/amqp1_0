//
// Created by Gabriele Santomaggio on 12/03/23.
//

#include "encode.h"
#include <stdlib.h>
#include <memory.h>


void write_amqp1_0_to_buffer(PMessage_t message, unsigned char *buffer){
    memcpy(buffer, message->bodyAmqpData->body, sizeof(char) * message->bodyAmqpData->body_len);
}
