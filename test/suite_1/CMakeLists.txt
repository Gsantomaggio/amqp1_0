add_subdirectory(resources)
add_executable(message_encode_decode
        message_encode_decode.c
        )

target_link_libraries(message_encode_decode
        amqp_lib
        Unity
        )

add_test(suite_1_test message_encode_decode)
