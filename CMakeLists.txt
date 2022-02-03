cmake_minimum_required(VERSION 3.16)
project(ffp_tum)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fPIC -Wall -Wextra -fsanitize=address -g -march=native")
include_directories(include)
add_executable(ffp_tum src/main.cpp src/Model.cpp src/GUI.cpp src/Person.cpp include/randomGenerator.hpp src/randomGenerator.cpp)
target_link_libraries(ffp_tum SDL2main SDL2 SDL2_image)
