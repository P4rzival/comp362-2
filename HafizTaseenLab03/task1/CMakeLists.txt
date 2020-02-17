# Name: Taseen Hafiz
# Lab/task: Lab 03
# Date: 02/17/2020

#memory_layout process_creation
project(Lab03Task1 C)

set(CMAKE_C_STANDARD 11)

SET(CMAKE_C_FLAGS "-m64 -g -O0 -D_DEBUG -Wall")

set(SOURCE1 memory_layout.c)
set(SOURCE2 process_creation.c)

set(CMAKE_BUILD_TYPE Debug)

add_executable( memory_layout ${SOURCE1})

add_executable( process_creation ${SOURCE2})
