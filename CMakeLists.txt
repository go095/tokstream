cmake_minimum_required(VERSION 2.6)

####
# The tokstream project
####

project(TOKSTREAM)

# use ./lib and ./bin folders for output files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${TOKSTREAM_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TOKSTREAM_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TOKSTREAM_SOURCE_DIR}/bin)

# the tokstream library
add_library(tokstream
    tokstream/tokstream.h
    tokstream/tokstream.c
)

####
# Example projects
####

add_subdirectory(examples)
