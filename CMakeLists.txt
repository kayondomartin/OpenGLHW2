cmake_minimum_required(VERSION 3.20)
project(OpenHW2)

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenHW2 main.cpp)
target_link_libraries(OpenHW2 -lglut -lGL -lGLU)
