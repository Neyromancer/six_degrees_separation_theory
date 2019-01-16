find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(network network.cpp)
target_link_libraries(network user)
add_executable(networkTest main.cpp)
target_link_libraries(networkTest ${GTEST_LIBRARIES} network pthread)
