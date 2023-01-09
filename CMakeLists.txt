cmake_minimum_required(VERSION 3.24)
project(NES)

set(CMAKE_CXX_STANDARD 17)

add_executable(NES main.cpp Bus.cpp Bus.h olc6502.cpp olc6502.h)
