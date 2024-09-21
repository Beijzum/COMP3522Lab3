cmake_minimum_required(VERSION 3.29)
project(lab3template)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3template main.cpp
        myStack.cpp
        myStack.hpp
        catch.hpp
        unit_tests.cpp
)
