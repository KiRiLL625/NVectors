cmake_minimum_required(VERSION 3.27)
project(vector_n)

set(CMAKE_CXX_STANDARD 17)

add_executable(vector_n main.cpp
        NVector.cpp
        NVector.h)
