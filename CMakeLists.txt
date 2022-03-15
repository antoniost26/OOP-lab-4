cmake_minimum_required(VERSION 3.21)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 main.cpp classes/Triangle.cpp classes/Triangle.h classes/Point.cpp classes/Point.h tests/tests.cpp tests/tests.h)
