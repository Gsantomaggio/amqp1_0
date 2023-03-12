add_executable(fuzz_amqp_app fuzz_me.c)

target_compile_options(fuzz_amqp_app
        PRIVATE -g -fsanitize=address,fuzzer
        )

target_link_libraries(fuzz_amqp_app
        PRIVATE -fsanitize=address,fuzzer
        amqp_lib
        )