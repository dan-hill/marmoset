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
    marmoset/debug.h
    marmoset/die_with_error.h
    marmoset/app_m.h
    app/app.h
    app/index/index.h
    marmoset/abort.h
    marmoset/mime_type.h
    marmoset/response_status.h
    marmoset/http_method.h
    marmoset/http_request.h
    marmoset/serializer.h
    marmoset/marmoset.h
    marmoset/respond.h
    )

set(PROJECT_SOURCES
    app/app.c
    marmoset/debug.c
    marmoset/die_with_error.c
    marmoset/app_m.c
    app/index/index.c
    marmoset/abort.c
    marmoset/mime_type.c
    marmoset/response_status.c
    marmoset/http_method.c
    marmoset/serializer.c
    marmoset/marmoset.c
    marmoset/respond.c
    )

add_executable(app app/app.c ${PROJECT_HEADERS} ${PROJECT_SOURCES})

