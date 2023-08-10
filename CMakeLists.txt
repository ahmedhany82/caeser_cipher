cmake_minimum_required(VERSION 3.25)
project(caeser_cipher C)

set(CMAKE_C_STANDARD 17)

set(SOURCES
    main.c
    rot13.c
    find_key.c
    stdin_reader.c)

add_executable(caeser_cipher ${SOURCES})
target_include_directories(caeser_cipher PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})