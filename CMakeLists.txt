cmake_minimum_required(VERSION 3.0)

project(sktshow)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

include_directories(xsocket)

add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(examples)