cmake_minimum_required(VERSION 3.7)
project(data_structure)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")

set(SOURCE_FILES main.cpp)
add_executable(data_structure ${SOURCE_FILES})