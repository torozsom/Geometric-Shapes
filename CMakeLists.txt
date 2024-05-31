cmake_minimum_required(VERSION 3.28)
project(NHF)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DMEMTRACE)

add_executable(NHF
        Figure.hpp
        Circle.hpp
        Circle.cpp
        Polygon.hpp
        Polygon.cpp
        Point.cpp
        Point.hpp
        Triangle.hpp
        Square.hpp
        Shapes.cpp
        Shapes.hpp
        String.hpp
        memtrace.cpp
        memtrace.h
        String.cpp
        Controls.cpp
        Controls.hpp
        main.cpp
        Test.cpp
        Test.hpp
)
