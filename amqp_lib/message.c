//
// Created by Gabriele Santomaggio on 12/03/23.
//

#include "message.h"


void free_message_fields(PMessage_t msg) {
    if (msg->bodyAmqpData != NULL) {
        if (msg->bodyAmqpData->body != NULL) {
            free(msg->bodyAmqpData->body);
        }
        free(msg->bodyAmqpData);
    }
}

void malloc_amqp_data(PMessage_t msg, size_t __size) {
    msg->bodyAmqpData = malloc(sizeof(BODY_AMQP_DATA));
    msg->bodyAmqpData->body = malloc(sizeof(unsigned char) * __size);
    msg->bodyAmqpData->body_len = __size;
}
