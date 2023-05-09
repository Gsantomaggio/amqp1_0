//
// Created by Gabriele Santomaggio on 19/02/23.
//


#include <unity.h>
#include <types.h>
#include <message.h>
#include <string.h>
#include <unistd.h>


int read_amqp_buffer_from_file(char *filename, unsigned char *buffer, long *len) {
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


void test_unmarshal_described_format_code(void) {
    unsigned char formatBuff[] = {0x03, 0x11, APPLICATION_DATA};
    DescribedFormatCode formatCode;
    unmarshal_described_format_code(formatBuff, &formatCode);
    TEST_ASSERT_EQUAL_CHAR(0x03, formatCode.v1);
    TEST_ASSERT_EQUAL_CHAR(0x11, formatCode.v2);
    TEST_ASSERT_EQUAL_CHAR(0x75, formatCode.formatCode);
    TEST_ASSERT_EQUAL_INT(3, formatCode.size);
}


void test_marshal_unmarshal_described_format_code(void) {
    DescribedFormatCode formatCode;
    formatCode.v1 = 0x04;
    formatCode.v2 = 0x02;
    formatCode.formatCode = 0x06;
    unsigned char *formatBuff = malloc(sizeof(unsigned char) * described_format_code_size());
    marshal_described_format_code(&formatCode, formatBuff);

    DescribedFormatCode formatCodeResult;
    unmarshal_described_format_code(formatBuff, &formatCodeResult);
    TEST_ASSERT_EQUAL_CHAR(0x04, formatCodeResult.v1);
    TEST_ASSERT_EQUAL_CHAR(0x02, formatCodeResult.v2);
    TEST_ASSERT_EQUAL_CHAR(0x06, formatCodeResult.formatCode);
    free(formatBuff);
}

void test_message_unmarshal_application_data_v8(void) {
    unsigned char formatBuff[] = {0x03, 0x11, APPLICATION_DATA, FORMAT_CODE_VBIN8, 0x01, 0x02};
    Message_t msg;
    Unmarshal(formatBuff, 6, &msg);

    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);
    TEST_ASSERT_EQUAL_CHAR(0x02, msg.bodyAmqpData->body[0]);
    free_message_fields(&msg);
}


void test_message_marshal_unmarshal_application_data_v8(void) {
    Message_t msgSource;
    malloc_amqp_data(&msgSource, 10);
    memcpy(msgSource.bodyAmqpData->body, "1234567890", msgSource.bodyAmqpData->body_len);
    MESSAGE_DATA buff = Marshal(&msgSource);
    Message_t msgDestination;
    Unmarshal(buff.payload, buff.payload_len, &msgDestination);
//
    TEST_ASSERT_NOT_EMPTY(msgDestination.bodyAmqpData->body);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("1234567890",
                                 msgDestination.bodyAmqpData->body,
                                 msgSource.bodyAmqpData->body_len);
    free_message_fields(&msgSource);
    free_message_data(buff);
}


void test_message_unmarshal_application_data_v32(void) {
    unsigned char formatBuff[] = {0x03, 0x11, APPLICATION_DATA, // format code
                                  FORMAT_CODE_Vbin32, //FORMAT_CODE_Vbin32
                                  0x00, 0x00, 0x00, 0x09, // 9 big endian
                                  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09 // byte buffer
    };
    Message_t msg;
    Unmarshal(formatBuff, sizeof(formatBuff), &msg);
    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);
    unsigned char expected[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
    TEST_ASSERT_EQUAL_INT(9, msg.bodyAmqpData->body_len);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, msg.bodyAmqpData->body, 9);
    free_message_fields(&msg);
}

//
//
void test_message_unmarshal_application_data_from_file_body_v8(void) {
    unsigned char formatBuff[1024];
    long len;
    read_amqp_buffer_from_file("message_body_this_is_a_amqp_message", formatBuff, &len);
    Message_t msg;
    Unmarshal(formatBuff, len, &msg);
    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);

    unsigned char expected[] = "this_is_a_amqp_message";
    ///

    TEST_ASSERT_EQUAL_INT(22, msg.bodyAmqpData->body_len);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, msg.bodyAmqpData->body, msg.bodyAmqpData->body_len);
    free_message_fields(&msg);
}

//
void test_message_unmarshal_application_data_from_file_body_32(void) {
    unsigned char formatBuff[1024];
    long len;
    read_amqp_buffer_from_file("message_body_700", formatBuff, &len);
    Message_t msg;
    Unmarshal(formatBuff, len, &msg);
    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);
    TEST_ASSERT_TRUE(msg.bodyAmqpData->body_len == 700);
    free_message_fields(&msg);
}

//
//
void test_message_unmarshal_application_data_from_file_unicode_body_32(void) {
    unsigned char formatBuff[1024];
    long len;
    read_amqp_buffer_from_file("message_body_unicode_500_body", formatBuff, &len);
    Message_t msg;
    Unmarshal(formatBuff, len, &msg);
    TEST_ASSERT_NOT_EMPTY(msg.bodyAmqpData->body);
    unsigned char expected[] =
            "Alan Mathison Turing（1912 年 6 月 23 日 - 1954 年 6 月 7 日）是英国数学家、计算机科学家、逻辑学家、密码分析家、哲学家和理论生物学家。 [6] 图灵在理论计算机科学的发展中具有很大的影响力，用图灵机提供了算法和计算概念的形式化，可以被认为是通用计算机的模型。[7][8][9] 他被广泛认为是理论计算机科学和人工智能之父。 [10]";
    TEST_ASSERT_EQUAL_INT(435, msg.bodyAmqpData->body_len);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, msg.bodyAmqpData->body, msg.bodyAmqpData->body_len);
    free_message_fields(&msg);
}

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_unmarshal_described_format_code);
    RUN_TEST(test_marshal_unmarshal_described_format_code);
    RUN_TEST(test_message_unmarshal_application_data_v8);
    RUN_TEST(test_message_unmarshal_application_data_v32);
    RUN_TEST(test_message_unmarshal_application_data_from_file_body_v8);
    RUN_TEST(test_message_unmarshal_application_data_from_file_body_32);
    RUN_TEST(test_message_unmarshal_application_data_from_file_unicode_body_32);
    RUN_TEST(test_message_marshal_unmarshal_application_data_v8);
    return UNITY_END();
}