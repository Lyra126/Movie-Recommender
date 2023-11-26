cmake_minimum_required(VERSION 3.24)
project(dsaprojectthree)

set(CMAKE_CXX_STANDARD 14)

add_executable(dsaprojectthree
        src/info.cpp src/httplib.h)

target_link_libraries(dsaprojectthree ws2_32)
