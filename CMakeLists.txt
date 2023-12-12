cmake_minimum_required(VERSION 3.15)
project(Sudoku)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(-Wall -Wextra -pedantic -g)
add_executable(minesweeper main.cpp Minesweeper.cpp Cell.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)