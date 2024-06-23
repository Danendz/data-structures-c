cmake_minimum_required(VERSION 3.28)
project(data_structures_c C)

set(CMAKE_C_STANDARD 23)

add_executable(data_structures_c src/main.c
        src/array.c
        src/array.h)
