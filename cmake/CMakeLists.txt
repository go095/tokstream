cmake_minimum_required(VERSION 2.6)

project(tokstream)

set(TOKSTREAM_ROOT_DIR ${PROJECT_SOURCE_DIR}/..)

message("Project Source Dir: " ${PROJECT_SOURCE_DIR})
message("tokstream Root Dir: " ${TOKSTREAM_ROOT_DIR})

set(LIBRARY_OUTPUT_PATH ${TOKSTREAM_ROOT_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${TOKSTREAM_ROOT_DIR}/bin)

add_library(tokstream
    ${TOKSTREAM_ROOT_DIR}/tokstream/tokstream.h
    ${TOKSTREAM_ROOT_DIR}/tokstream/tokstream.c
)

add_subdirectory(examples)
