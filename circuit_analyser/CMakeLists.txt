cmake_minimum_required(VERSION 3.29)
project(circuit_analyser)

set(CMAKE_CXX_STANDARD 20)

add_executable(circuit_analyser main.cpp
        stardelta.cpp
        op_amp.cpp
        HPLP.cpp)
