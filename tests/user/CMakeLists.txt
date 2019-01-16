find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(user user.cpp)
target_include_directories(user PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(userTest main.cpp)
target_link_libraries(userTest ${GTEST_LIBRARIES} user pthread)
