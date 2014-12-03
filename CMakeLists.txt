cmake_minimum_required (VERSION 2.6)

project(marmoset)
project(C_ONLY C)
set(CMAKE_C_FLAGS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "~/Development/marmoset/bin/")
set(CMAKE_C_COMPILER gcc)
include_directories(
    marmoset
    marmoset/session
    app
    )

set(PROJECT_HEADERS
    marmoset/debug/debug.h
    marmoset/error/die_with_error.h
    marmoset/session/app_m.h
    app/app.h
    app/index/index.h
    marmoset/error/abort.h
    marmoset/session/mime_type.h
    marmoset/session/response_status.h
    marmoset/session/http_method.h
    marmoset/session/http_request.h
    marmoset/session/serializer.h
    marmoset/marmoset.h
    marmoset/session/respond.h
    app/hardware/hardware.h
    )

set(PROJECT_SOURCES
    app/app.c
    marmoset/debug/debug.c
    marmoset/error/die_with_error.c
    marmoset/session/app_m.c
    app/index/index.c
    marmoset/error/abort.c
    marmoset/session/mime_type.c
    marmoset/session/response_status.c
    marmoset/session/http_method.c
    marmoset/session/serializer.c
    marmoset/marmoset.c
    marmoset/session/respond.c
    app/hardware/hardware.c
    )

add_executable(app app/app.c ${PROJECT_HEADERS} ${PROJECT_SOURCES})

