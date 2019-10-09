cmake_minimum_required(VERSION 3.15)
project(cprogutil C)

set(CMAKE_C_STANDARD 99)

add_library(cprogutil
        queue.c queue.h
        unionfind.c unionfind.h
        bitset.h
        boolean.h
        allocate_sprint.c allocate_sprint.h
)