//
// Created by Gabriele Santomaggio on 23/02/23.
//

#ifndef AMQP1_0_TYPES_H
#define AMQP1_0_TYPES_H

#include <stdlib.h>

#define APPLICATION_DATA  0x75
//const char MessageAnnotations = 0x72;
//const char MessageProperties = 0x73;
//const char ApplicationProperties = 0x74;
//const char MessageHeader = 0x70;
//const char AmqpValue = 0x77;

#define FORMAT_CODE_VBIN8 (char)0xa0
#define FORMAT_CODE_Vbin32 (char)0xb0


typedef struct BODY_AMQP_DATA_S {
    char *body;
    size_t body_len;
} BODY_AMQP_DATA;

typedef struct {
    BODY_AMQP_DATA *bodyAmqpData;
} Message_t, *PMessage_t;


typedef struct {
    char v1;
    char v2;
    char formatCode;
    int size;

} DescribedFormatCode, *PDescribedFormatCode;



#endif //AMQP1_0_TYPES_H
