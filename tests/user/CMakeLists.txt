cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(gtest_user_test)
set(CMAKE_CXX_STANDARD 14)


find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(user user.cpp)
add_executable(userTest main.cpp)
target_link_libraries(userTest ${GTEST_LIBRARIES} user pthread)
