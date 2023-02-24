//
// Created by Gabriele Santomaggio on 19/02/23.
//


#include <unity.h>
#include <decode.h>
#include <types.h>


//void test_New_Message(void) {
//    PMessage_t msg = newMessage();
//    TEST_ASSERT_NOT_EMPTY(&msg);
//}

void test_DecodeDescribedFormatCode(void) {
    char formatBuff[] = {0x03, 0x11, APPLICATION_DATA};
    DescribedFormatCode formatCode;
    decodeDescribedFormatCode(formatBuff, &formatCode);
    TEST_ASSERT_EQUAL_CHAR(0x03, formatCode.v1);
    TEST_ASSERT_EQUAL_CHAR(0x11, formatCode.v2);
    TEST_ASSERT_EQUAL_CHAR(0x75, formatCode.formatCode);
    TEST_ASSERT_EQUAL_INT(3, formatCode.size);
}

void test_MessageParseApplicationDataV8(void) {
    char formatBuff[] = {0x03, 0x11, APPLICATION_DATA, 0xa0, 0x01, 0x02};
    Message_t msg;
    parseAmqp10MessageBuffer(formatBuff, 6, &msg);
    TEST_ASSERT_NOT_EMPTY(msg.data);
    TEST_ASSERT_EQUAL_CHAR(0x02, msg.data[0]);
}

void test_MessageParseApplicationDataV32(void) {
    char formatBuff[] = {0x03, 0x11, APPLICATION_DATA, // format code
                         0xb0, //FORMAT_CODE_Vbin32
                         0x00, 0x00, 0x00, 0x09, // 9 big endian
                         0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09 // byte buffer
    };
    Message_t msg;
    parseAmqp10MessageBuffer(formatBuff, sizeof(formatBuff), &msg);
    TEST_ASSERT_NOT_EMPTY(msg.data);
    char expected[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, msg.data, 9);
}


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main(void) {
    UNITY_BEGIN();
//    RUN_TEST(test_New_Message);
    RUN_TEST(test_DecodeDescribedFormatCode);
    RUN_TEST(test_MessageParseApplicationDataV8);
    RUN_TEST(test_MessageParseApplicationDataV32);
    return UNITY_END();
}