cmake_minimum_required(VERSION 3.8)
project(Pong)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)

link_directories(/usr/local/lib)
link_libraries(sfml-window sfml-system sfml-graphics)


set(SOURCE_FILES main.cpp pad.cpp ball.cpp ball.h)
add_executable(Pong ${SOURCE_FILES})