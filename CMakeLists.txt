cmake_minimum_required (VERSION 2.6)

project(marmoset)
project(C_ONLY C)

set(CMAKE_C_COMPILER gcc)

set(PROJECT_HEADERS debug.h die_with_error.h http_header.h request.h)
set(PROJECT_SOURCES debug.c die_with_error.c http_header.c request.c)

add_executable(marmoset main.c ${PROJECT_HEADERS} ${PROJECT_SOURCES})