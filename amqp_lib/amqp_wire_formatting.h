//
// Created by Gabriele Santomaggio on 19/02/23.
//

#ifndef AMQP1_0_AMQP_WIRE_FORMATTING_H
#define AMQP1_0_AMQP_WIRE_FORMATTING_H

#include <types.h>
#include <message.h>

size_t read_char(const unsigned char *source_buffer, unsigned char *out_value);

size_t read_int(const unsigned char *source_buffer, unsigned int *out_value);

size_t read_type(const unsigned char *source_buffer, unsigned char *out_value);

size_t read_buffer(const unsigned char *source_buffer, unsigned char *out_value, size_t len);

size_t read_application_data(const unsigned char *source_buffer, PMessage_t message);


int write_pchar(const unsigned char *source_char, unsigned char *destination_char);
int write_char(const unsigned char source_char, unsigned char *destination_char);

int write_int( const int source, unsigned char *destination_char);


int write_chars(const unsigned char *source_char, unsigned char *destination_char, size_t len);

#endif //AMQP1_0_AMQP_WIRE_FORMATTING_H
