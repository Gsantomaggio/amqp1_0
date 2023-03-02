//
// Created by Gabriele Santomaggio on 19/02/23.
//

#ifndef AMQP1_0_AMQP_WIRE_FORMATTING_H
#define AMQP1_0_AMQP_WIRE_FORMATTING_H

#include <stdlib.h>
#include <string.h>
#include <types.h>
#include <stdint.h>

size_t read_char(uint8_t *source_buffer, uint8_t *out_value);
size_t read_int(uint8_t *source_buffer, uint32_t *out_value);
size_t read_type(uint8_t *source_buffer, uint8_t *out_value);

size_t read_buffer(uint8_t *source_buffer, uint8_t *out_value, size_t len);
size_t read_application_data(uint8_t *source_buffer, PMessage_t message);

#endif //AMQP1_0_AMQP_WIRE_FORMATTING_H
