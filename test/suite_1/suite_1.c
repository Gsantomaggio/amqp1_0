//
// Created by Gabriele Santomaggio on 19/02/23.
//


#include <unity.h>
#include <library.h>


void test_New_Message(void) {
    PMessage_t msg = newMessage();
    TEST_ASSERT_NOT_EMPTY(&msg);
}

void test_DecodeDescribedFormatCode(void) {
    char formatBuff[] = {0x01, 0x11,  APPLICATION_DATA};
    DescribedFormatCode d = decodeDescribedFormatCode(formatBuff);
    TEST_ASSERT_EQUAL_CHAR(0x01, d.v1);
    TEST_ASSERT_EQUAL_CHAR(0x11, d.v2);
    TEST_ASSERT_EQUAL_CHAR( 0x75, d.formatCode);
    TEST_ASSERT_EQUAL_INT(3, d.size);
}


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_New_Message);
    RUN_TEST(test_DecodeDescribedFormatCode);
    return UNITY_END();
}