cmake_minimum_required(VERSION 3.12)
project(lab03 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab03
        BinTree.c
        BinTree.h
        main.c
        main.h
        queue.c
        queue.h
        )
