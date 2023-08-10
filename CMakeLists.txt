cmake_minimum_required(VERSION 3.25)
project(caeser_cipher C)

set(CMAKE_C_STANDARD 17)

set(SOURCES
        src/main.c
        src/rot13.c
        src/find_key.c
        src/stdin_reader.c)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(caeser_cipher ${SOURCES})
target_include_directories(caeser_cipher PUBLIC ${INCLUDE_DIR})