cmake_minimum_required(VERSION 2.6)

project(tokstream)

set(TOKSTREAM_ROOT_DIR ${PROJECT_SOURCE_DIR}/..) 

message("Project Source Dir: " ${PROJECT_SOURCE_DIR})
message("tokstream Root Dir: " ${TOKSTREAM_ROOT_DIR})

add_library(tokstream
    ${TOKSTREAM_ROOT_DIR}/tokstream/tokstream.h
    ${TOKSTREAM_ROOT_DIR}/tokstream/tokstream.c
)

add_subdirectory(examples)
