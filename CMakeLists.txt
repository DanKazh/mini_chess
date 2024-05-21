cmake_minimum_required(VERSION 3.15)
project(chess-project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SOURCES
    main.cpp
    menu.cpp
    board.cpp
    window.cpp
)

set(HEADERS
    menu.hpp
    board.hpp
    window.hpp
)

add_executable(chess-project ${SOURCES} ${HEADERS})

set(SFML_DIR "D:\sfml\SFML-2.6.x\cmake")

find_package(SFML 2.6.1 REQUIRED COMPONENTS system window graphics network audio)

target_include_directories(chess-project PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(chess-project sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
