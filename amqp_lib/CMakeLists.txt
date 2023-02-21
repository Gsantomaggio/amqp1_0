add_library(amqp_lib STATIC
        library.h
        library.c
        amqp_wire_formatting.h
        amqp_wire_formatting.c
        )

target_include_directories(amqp_lib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )