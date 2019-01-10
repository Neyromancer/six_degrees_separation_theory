cmake_minimum_required (VERSION 3.10)
project (six_degrees_separation_theory)
set (six_degrees_separation_theory_VERSION_MAJOR 1)
set (six_degrees_separation_theory_VERSION_MINOR 0)

configure_file (
  "${PROJECT_SOURCE_DIR}/six_degrees_separation_theory_config.h.in"
  "${PROJECT_BINARY_DIR}/six_degrees_separation_theory_config.h"
)

include_directories ("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/user")
add_subdirectory (user)

add_executable (six_handshake_test main.cpp)
target_link_libraries(six_handshake_test user)

install (TARGETS six_handshake_test DESTINATION
/home/dmitry/workspace/git/)
