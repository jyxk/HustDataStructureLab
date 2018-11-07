cmake_minimum_required(VERSION 3.12)
project(lab01 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab01
        ArrayList.c
        ArrayList.h
        main.c
        main.h)
