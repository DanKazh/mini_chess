cmake_minimum_required(VERSION 3.23)
set(project "mini-chess")
project(${project})
set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
board.cpp, window.cpp, main.cpp)
set(${project}_HEADERS
board.hpp, window.hpp)
set(${project}_SOURCES_LIST
    ${${project}_SOURCES}
    ${${project}_HEADERS})
add_library(${project}
    STATIC
    &{${project}_SOURCES_LIST})
