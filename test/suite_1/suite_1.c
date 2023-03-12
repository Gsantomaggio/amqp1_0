//
// Created by Gabriele Santomaggio on 19/02/23.
//


#include <unity.h>
#include <decode.h>
#include <types.h>
#include <string.h>
#include <unistd.h>


int readAmqpBufferFromFile(char *filename, unsigned char *buffer, long *len) {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }

    FILE *fileptr;
    strcat(cwd, "/resources/");
    strcat(cwd, filename);
    fileptr = fopen(cwd, "rb");  // Open the file in binary mode
    if (fileptr == NULL) {
        perror("can't open file");
        return 0;
    }
    fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
    *len = ftell(fileptr);             // Get the current byte offset in the file
    rewind(fileptr);                      // Jump back to the beginning of the file

    size_t read = fread(buffer, sizeof(unsigned char), *len, fileptr); // Read in the entire file
    fclose(fileptr); // Close the file
    return read;
}


void test_DecodeDescribedFormatCode(void) {
    unsigned char formatBuff[] = {0x03, 0x11, APPLICATION_DATA};
    DescribedFormatCode formatCode;
    decodeDescribedFormatCode(formatBuff, &formatCode);
    TEST_ASSERT_EQUAL_CHAR(0x03, formatCode.v1);
    TEST_ASSERT_EQUAL_CHAR(0x11, formatCode.v2);
    TEST_ASSERT_EQUAL_CHAR(0x75, formatCode.formatCode);
    TEST_ASSERT_EQUAL_INT(3, formatCode.size);
}

void test_MessageParseApplicationDataV8(void) {
//    unsigned char formatBuff[] = {0x03, 0x11, APPLICATION_DATA, FORMAT_CODE_VBIN8, 0x01, 0x02};
    unsigned char formatBuff[] = {0x3, 0x11, 0x75, 0xa0, 0x1, 0x2, 0x2a, 0x03, 0x11u, 0xa0, 0x01, 0x02};
    Message_t msg;
    parse_amqp10_message_buffer(formatBuff, 6, &msg);

    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);
    TEST_ASSERT_EQUAL_CHAR(0x02, msg.bodyAmqpData->body[0]);
    freeMessageFields(&msg);
}

void test_MessageParseApplicationDataV32(void) {
    unsigned char formatBuff[] = {0x03, 0x11, APPLICATION_DATA, // format code
                                  FORMAT_CODE_Vbin32, //FORMAT_CODE_Vbin32
                                  0x00, 0x00, 0x00, 0x09, // 9 big endian
                                  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09 // byte buffer
    };
    Message_t msg;
    parse_amqp10_message_buffer(formatBuff, sizeof(formatBuff), &msg);
    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);
    unsigned char expected[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
    TEST_ASSERT_EQUAL_size_t((size_t) 9, msg.bodyAmqpData->body_len);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, msg.bodyAmqpData->body, 9);
    freeMessageFields(&msg);
}

//
//
void test_MessageParseApplicationDataFromFileBodyV8(void) {
    unsigned char formatBuff[1024];
    long len;
    readAmqpBufferFromFile("message_body_this_is_a_amqp_message", formatBuff, &len);
    Message_t msg;
    parse_amqp10_message_buffer(formatBuff, len, &msg);
    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);

    unsigned char expected[] = "this_is_a_amqp_message";
    ///

    TEST_ASSERT_EQUAL_size_t(22, msg.bodyAmqpData->body_len);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, msg.bodyAmqpData->body, msg.bodyAmqpData->body_len);
    freeMessageFields(&msg);
}

//
void test_MessageParseApplicationDataFromFileBody32(void) {
    unsigned char formatBuff[1024];
    long len;
    readAmqpBufferFromFile("message_body_700", formatBuff, &len);
    Message_t msg;
    parse_amqp10_message_buffer(formatBuff, len, &msg);
    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);
    TEST_ASSERT_TRUE(msg.bodyAmqpData->body_len == 700);
    freeMessageFields(&msg);
}

//
//
void test_MessageParseApplicationDataFromFileUnicodeBody32(void) {
    unsigned char formatBuff[1024];
    long len;
    readAmqpBufferFromFile("message_body_unicode_500_body", formatBuff, &len);
    Message_t msg;
    parse_amqp10_message_buffer(formatBuff, len, &msg);
    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);
    unsigned char expected[] =
            "Alan Mathison Turing（1912 年 6 月 23 日 - 1954 年 6 月 7 日）是英国数学家、计算机科学家、逻辑学家、密码分析家、哲学家和理论生物学家。 [6] 图灵在理论计算机科学的发展中具有很大的影响力，用图灵机提供了算法和计算概念的形式化，可以被认为是通用计算机的模型。[7][8][9] 他被广泛认为是理论计算机科学和人工智能之父。 [10]";
    TEST_ASSERT_EQUAL_size_t(435, msg.bodyAmqpData->body_len);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, msg.bodyAmqpData->body, msg.bodyAmqpData->body_len);
    freeMessageFields(&msg);
}

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_DecodeDescribedFormatCode);
    RUN_TEST(test_MessageParseApplicationDataV8);
    RUN_TEST(test_MessageParseApplicationDataV32);
    RUN_TEST(test_MessageParseApplicationDataFromFileBodyV8);
    RUN_TEST(test_MessageParseApplicationDataFromFileBody32);
    RUN_TEST(test_MessageParseApplicationDataFromFileUnicodeBody32);
    return UNITY_END();
}