cmake_minimum_required(VERSION 3.17)
project(amqp1_0 C)

set(CMAKE_C_STANDARD 99)
include_directories(.)
include_directories(unity/src)


add_executable(amqp1_0
        test/TestLibrary.c
        unity/src/unity.c
        unity/src/unity.h
        unity/src/unity_internals.h
        amqp_wire_formatting.c
        amqp_wire_formatting.h
        library.c
        library.h)