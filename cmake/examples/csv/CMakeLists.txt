project(tokstream_csv)

add_executable(csv
  ${EXAMPLES_ROOT_DIR}/csv/csv.c
)

target_link_libraries(csv tokstream)
