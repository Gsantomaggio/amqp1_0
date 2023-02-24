//
// Created by Gabriele Santomaggio on 19/02/23.
//

#ifndef AMQP1_0_AMQP_WIRE_FORMATTING_H
#define AMQP1_0_AMQP_WIRE_FORMATTING_H

#include <string.h>
#include <types.h>

int read_char(char *source_buffer, char *out_value);
int read_int(char *source_buffer, int *out_value);
int read_type(char *source_buffer, char *out_value);

int read_buffer(char *source_buffer, char *out_value, size_t len);
int read_application_data(char *source_buffer, PMessage_t message);

#endif //AMQP1_0_AMQP_WIRE_FORMATTING_H
