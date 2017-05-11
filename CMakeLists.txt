cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AI.cpp AI.h chess_type.cpp chess_type.h)
add_executable(GobangAi ${SOURCE_FILES})