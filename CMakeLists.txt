cmake_minimum_required(VERSION 3.21)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 main.cpp classes/Triangle.cpp classes/Triangle.h classes/Point.cpp classes/Point.h tests/tests.cpp tests/tests.h operations/point_operations.cpp operations/point_operations.h UI/menu.cpp UI/menu.h UIModules/IOModules.cpp UIModules/IOModules.h TriangleRepository/TriangleRepository.cpp TriangleRepository/TriangleRepository.h)
