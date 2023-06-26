cmake_minimum_required(VERSION 3.10)
project(Server)

set(CMAKE_CXX_STANDARD 11)

# Main server
add_executable(server src/main.cpp src/server.cpp)
target_link_libraries(server boost_system)

# Tests
add_executable(server_test tests/server_test.cpp src/server.cpp)
target_link_libraries(server_test boost_system gtest pthread)
