cmake_minimum_required(VERSION 3.16)
project(ffp_tum)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fPIC -Wall -Wextra -fsanitize=address -g -march=native")
include_directories(include)
add_executable(ffp_tum src/main.cpp src/GUI.cpp src/Person.cpp)
target_link_libraries(ffp_tum SDL2main SDL2 SDL2_image)

# GUI Tests
include_directories(include)
add_executable(GUI_test src/GUI.cpp src/Person.cpp)
target_link_libraries(GUI_test SDL2main SDL2 SDL2_image)