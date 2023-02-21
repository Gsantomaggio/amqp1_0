project(amqp1_0 C)
cmake_minimum_required(VERSION 3.17)
set(TARGET_GROUP production CACHE STRING "Group to build")


add_subdirectory(amqp_lib)


if (TARGET_GROUP STREQUAL test)
    include(CTest)
    add_subdirectory(external)
    add_subdirectory(test)
endif ()