//
// Created by Gabriele Santomaggio on 12/03/23.
//

#ifndef AMQP1_0_MESSAGE_H
#define AMQP1_0_MESSAGE_H

#include <stdlib.h>


typedef struct BODY_AMQP_DATA_S {
    unsigned char *body;
    int body_len;
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


typedef struct MESSAGE_DATA_S {
    unsigned char *payload;
    int payload_len;
} MESSAGE_DATA;


DescribedFormatCode CreateDescribedFormatCode(unsigned char formatCode);

int described_format_code_size();

void malloc_amqp_data(PMessage_t msg, size_t __size);

void free_message_fields(PMessage_t msg);

int message_size(PMessage_t message);

int Unmarshal(const unsigned char *source_buffer, long len, PMessage_t out_message);

int unmarshal_described_format_code(const unsigned char *source_buffer, PDescribedFormatCode out_described_format_code);

MESSAGE_DATA Marshal(PMessage_t message);

size_t marshal_described_format_code(PDescribedFormatCode pSourceDescribedFormatCode, unsigned char *destination_char);

int described_format_code_size();

void free_message_data(MESSAGE_DATA message_data);

#endif //AMQP1_0_MESSAGE_H
