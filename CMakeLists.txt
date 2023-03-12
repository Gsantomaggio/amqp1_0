project(amqp1_0 C)
cmake_minimum_required(VERSION 3.10)
set(TARGET_GROUP production CACHE STRING "Group to build")
option(FUZZ "Build With FUZZ" ON)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang)
add_subdirectory(amqp_lib)


include(CTest)
add_subdirectory(external)
add_subdirectory(test)

#if (FUZZ)
#    ## https://github.com/google/fuzzing/blob/master/tutorial/libFuzzerTutorial.md
#    message("--- Build with FUZZ")
#    add_subdirectory(fuzz)
#endif ()

