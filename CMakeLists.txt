cmake_minimum_required(VERSION 3.8)
project(service)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(echo)
add_subdirectory(http)
add_subdirectory(post)