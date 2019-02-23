cmake_minimum_required(VERSION 3.13)
project(more01)

set(CMAKE_CXX_STANDARD 11)

add_executable(more01 CH01/more01.c)
add_executable(more02 CH01/more02.c)
add_executable(cp1 CH02/cp1.c)
add_executable(cp01 CH02/cp01.c)
add_executable(utmplib CH02/utmplib.c)