cmake_minimum_required(VERSION 3.12)
project(lab02 C)

set(CMAKE_C_STANDARD 11)

set(BUILD_DIR .)  #设置编译目录,也就是Makefile文件所在目录
message(${BUILD_DIR}) #打印目录路径

add_custom_target(demo COMMAND make -C ${BUILD_DIR})


include_directories(.)

add_executable(lab02
        LinkedList.c
        LinkedList.h
        main.c
        main.h)

