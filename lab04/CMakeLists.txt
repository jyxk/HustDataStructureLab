cmake_minimum_required(VERSION 3.13)
project(lab04 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab04 main.c Graph.c Graph.h main.h queue.c queue.h)