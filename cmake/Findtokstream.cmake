cmake_minimum_required(VERSION 2.6)

####
# Find tokstream Library
####

# get tokstream library output property
get_property(TOKSTREAM_LIBRARY_OUTPUT_DIRECTORY
	TARGET tokstream
	PROPERTY LIBRARY_OUTPUT_DIRECTORY
)

# search locations
set(TOKSTREAM_INC_SEARCH_PATH
	${TOKSTREAM_SOURCE_DIR}/tokstream
)
set(TOKSTREAM_LIB_SEARCH_PATH
	${TOKSTREAM_LIBRARY_OUTPUT_DIRECTORY}
	${TOKSTREAM_SOURCE_DIR}/lib
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)

# find headers and library
find_path(TOKSTREAM_INCLUDE_DIR tokstream.h TOKSTREAM_INC_SEARCH_PATH)
find_library(TOKSTREAM_LIBRARY tokstream TOKSTREAM_LIB_SEARCH_PATH)

# check whether tokstream was found or not
if(TOKSTREAM_INCLUDE_DIR AND TOKSTREAM_LIBRARY)
   set(TOKSTREAM_FOUND TRUE)
endif(TOKSTREAM_INCLUDE_DIR AND TOKSTREAM_LIBRARY)

# status message
if(TOKSTREAM_FOUND)
   if(NOT tokstream_FIND_QUIETLY)
      message(STATUS "Found tokstream: ${TOKSTREAM_LIBRARY}")
   endif(NOT tokstream_FIND_QUIETLY)
else(TOKSTREAM_FOUND)
   if(tokstream_FIND_REQUIRED)
      message(FATAL_ERROR "Could not find tokstream")
   endif(tokstream_FIND_REQUIRED)
endif(TOKSTREAM_FOUND)
