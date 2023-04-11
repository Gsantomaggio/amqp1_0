#include <stdint.h>
#include <stddef.h>
#include  <stdio.h>
#include <decode.h>
#include <message.h>


int FuzzMe(const uint8_t *Data, size_t DataSize) {

    if (DataSize >= 6 &&
        Data[0] == 0x03 &&
        Data[1] == 0x11 &&
        Data[2] == APPLICATION_DATA &&
        Data[3] == FORMAT_CODE_VBIN8 &&
        Data[4] == 0x01 &&
        Data[5] == 0x02
            ) {
        Message_t msg;
        read_amqp1_0_from_buffer(Data, DataSize, &msg);
        free_message_fields(&msg);
        return 0;
    }
    return 1;

}

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    FuzzMe(Data, Size);
    return 0;
}
