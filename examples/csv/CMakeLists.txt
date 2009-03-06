cmake_minimum_required(VERSION 2.6)

####
# CSV Example
####

project(TOKSTREAM_CSV)

# the csv executable
add_executable(csv
  csv.c
)

# link with tokstream library
target_link_libraries(csv
	tokstream
)
