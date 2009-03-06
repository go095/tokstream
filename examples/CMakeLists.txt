cmake_minimum_required(VERSION 2.6)

####
# Example projects for tokstream
####

project(TOKSTREAM_EXAMPLES)

# include dir for tokstream
include_directories(${TOKSTREAM_SOURCE_DIR}/tokstream/)

# examples
add_subdirectory(csv)
