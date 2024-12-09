cmake_minimum_required(VERSION 3.29)
project(Op_Amp_V7_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Op_Amp_V7_1
    main.cpp
    op_amp.cpp
    op_amp.h)
