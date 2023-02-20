#ifndef AMQP1_0_LIBRARY_H
#define AMQP1_0_LIBRARY_H

#define APPLICATION_DATA  0x75
//const char MessageAnnotations = 0x72;
//const char MessageProperties = 0x73;
//const char ApplicationProperties = 0x74;
//const char MessageHeader = 0x70;
//const char AmqpValue = 0x77;


typedef struct {
    char *data;

} Message_t, *PMessage_t;


typedef struct {
    char v1;
    char v2;
    char formatCode;
    int size;

} DescribedFormatCode, *PDescribedFormatCode;


PMessage_t newMessage();

PMessage_t parseMessage(char *source_buffer);

DescribedFormatCode decodeDescribedFormatCode(char *source_buffer);


#endif //AMQP1_0_LIBRARY_H
