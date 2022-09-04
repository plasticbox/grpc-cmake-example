cmake_minimum_required(VERSION 3.23)
project(server)
set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_subdirectory(../proto
        ./proto
        )

add_executable(server main.cpp)
target_link_libraries(server
        PRIVATE
        proto
        )