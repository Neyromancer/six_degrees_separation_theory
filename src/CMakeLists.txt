cmake_minimum_required (VERSION 3.10)
project (six_degrees_separation_theory)
set (CMAKE_CXX_STANDARD 14)
set (six_degrees_separation_theory_VERSION_MAJOR 1)
set (six_degrees_separation_theory_VERSION_MINOR 0)

configure_file (
  "${PROJECT_SOURCE_DIR}/six_degrees_separation_theory_config.h.in"
  "${PROJECT_SOURCE_DIR}/six_degrees_separation_theory_config.h"
)

include_directories ("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/user")
include_directories ("${PROJECT_SOURCE_DIR}/network")
add_subdirectory (user)
add_subdirectory(network)

add_executable (six_handshake_test main.cpp)
target_link_libraries(six_handshake_test network)

install (TARGETS six_handshake_test DESTINATION
/home/dmitry/workspace/git/)
