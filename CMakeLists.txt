cmake_minimum_required(VERSION 3.16)
project(ffp_tum)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)

add_executable(ffp_tum src/main.cpp)
