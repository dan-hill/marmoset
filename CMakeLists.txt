cmake_minimum_required (VERSION 2.6)

project(marmoset)
project(C_ONLY C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "~/Development/marmoset/bin/")
set(CMAKE_C_COMPILER gcc)
include_directories(
    core
    core/session
    controller
    core/libs
    )

set(PROJECT_HEADERS
    core/debug/debug.h
    core/error/die_with_error.h
    core/session/request/http_request_parser.h
    core/session/request/request_handler.h
    core/session/response/response_handler.h
    controller/routes.h
    controller/index/index.h
    )

set(PROJECT_SOURCES
    core/debug/debug.c
    core/error/die_with_error.c
    core/session/request/http_request_parser.c
    core/session/request/request_handler.c
    core/session/response/response_handler.c
    controller/routes.c
    controller/index/index.c
    )

add_executable(marmoset core/main.c ${PROJECT_HEADERS} ${PROJECT_SOURCES})

