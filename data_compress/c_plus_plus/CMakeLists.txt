cmake_minimum_required(VERSION 3.7)
project(c_plus_plus)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")

set(SOURCE_FILES main.cpp)
add_executable(c_plus_plus ${SOURCE_FILES})