cmake_minimum_required(VERSION 3.17)
project(OPZ)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

include_directories(src) # необходимо для того, чтобы писать в директиве просто lib.h
include_directories(googletest/googletest/include)

set(SOURCE_FILES src/reversePolishNotationLib.cpp)

add_executable(main main.cpp ${SOURCE_FILES} src/reversePolishNotationLib.cpp src/reversePolishNotationLib.h)
add_executable(tests tests.cpp ${SOURCE_FILES})

target_link_libraries(tests gtest)