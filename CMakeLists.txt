cmake_minimum_required(VERSION 3.16)
project(ffp_tum)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
add_executable(ffp_tum src/main.cpp)

# GUI Tests
include_directories(include)
add_executable(GUI_test src/GUI.cpp)
target_link_libraries(GUI_test SDL2main SDL2)