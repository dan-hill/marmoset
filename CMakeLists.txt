cmake_minimum_required (VERSION 2.6)

project(marmoset)
project(C_ONLY C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "~/Development/marmoset/bin/")
set(CMAKE_C_COMPILER gcc)

set(PROJECT_HEADERS debug.h die_with_error.h http_request.h request.h string_utilities.h)
set(PROJECT_SOURCES debug.c die_with_error.c http_request.c request.c string_utilities.c)

add_executable(marmoset main.c ${PROJECT_HEADERS} ${PROJECT_SOURCES})