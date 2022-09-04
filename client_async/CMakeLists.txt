cmake_minimum_required(VERSION 3.23)
project(client_sync)
set(CMAKE_CXX_STANDARD 23)
set(OPENSSL_ROOT_DIR /opt/homebrew/opt/openssl)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(../proto
    ./proto
)

add_executable(client_sync main.cpp)
target_link_libraries(client_sync
    PRIVATE
        proto
)