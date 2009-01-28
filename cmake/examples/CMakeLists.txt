project(tokstream_examples)

include_directories(${TOKSTREAM_ROOT_DIR}/tokstream)

set(EXAMPLES_ROOT_DIR ${TOKSTREAM_ROOT_DIR}/examples)

subdirs(
  csv
)
