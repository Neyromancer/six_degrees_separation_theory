cmake_minimum_required(VERSION 3.8)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(userTest main.cpp)
target_link_libraries(userTest ${GTEST_LIBRARIES} pthread)
