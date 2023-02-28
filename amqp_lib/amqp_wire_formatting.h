//
// Created by Gabriele Santomaggio on 19/02/23.
//

#ifndef AMQP1_0_AMQP_WIRE_FORMATTING_H
#define AMQP1_0_AMQP_WIRE_FORMATTING_H

#include <stdlib.h>
#include <string.h>
#include <types.h>
#include <stdint.h>

size_t read_char(char *source_buffer, char *out_value);
size_t read_int(char *source_buffer, uint32_t *out_value);
size_t read_type(char *source_buffer, char *out_value);

size_t read_buffer(char *source_buffer, char *out_value, size_t len);
size_t read_application_data(char *source_buffer, PMessage_t message);

#endif //AMQP1_0_AMQP_WIRE_FORMATTING_H
