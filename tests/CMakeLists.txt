cmake_minimum_required (VERSION 3.10 FATAL_ERROR)
project (gtest_six_degrees_separation_theory)
set (CMAKE_CXX_STANDARD 14)

include_directories ("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/user")
include_directories ("${PROJECT_SOURCE_DIR}/network")
add_subdirectory (user)
add_subdirectory(network)
