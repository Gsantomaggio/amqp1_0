add_library(amqp_lib STATIC
        decode.h
        decode.c
        amqp_wire_formatting.h
        amqp_wire_formatting.c
        message.c message.h encode.c encode.h)

target_include_directories(amqp_lib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )