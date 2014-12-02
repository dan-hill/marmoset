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
    core/session/http_serialize.h
    core/session/request_handler.h
    core/session/response_handler.h
    controller/routes.h
    controller/index/index.h
    core/error/abort.h
    core/session/serializer.h
    core/session/mime_type.h
    core/session/response_status.h
    core/session/http_method.h
    controller/commander/commander.h
    )

set(PROJECT_SOURCES
    core/debug/debug.c
    core/error/die_with_error.c
    core/session/http_serialize.c
    core/session/request_handler.c
    core/session/response_handler.c
    controller/routes.c
    controller/index/index.c
    core/error/abort.c
    core/session/serializer.c
    core/session/mime_type.c
    core/session/response_status.c
    core/session/http_method.c
    controller/commander/commander.c
    )

add_executable(marmoset core/main.c ${PROJECT_HEADERS} ${PROJECT_SOURCES})

