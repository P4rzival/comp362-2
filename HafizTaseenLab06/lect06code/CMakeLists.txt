cmake_minimum_required(VERSION 3.12)
project(cpu_scheduling)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FILE_OFFSET_BITS=64")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall --pedantic -g -O0 -D_DEBUG")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(mynice mynice.c)
add_executable(queue_selection_20_80 queue_selection_20_80.c)
add_executable(roulette_wheel_selection roulette_wheel_selection.c)

add_executable(pthread_prio pthread_prio.c)
find_package(Threads)
target_link_libraries(pthread_prio ${CMAKE_THREAD_LIBS_INIT})


