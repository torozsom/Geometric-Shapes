cmake_minimum_required(VERSION 3.28)
project(GeometricShapes)

set(CMAKE_CXX_STANDARD 23)

add_definitions(-DMEMTRACE)

add_executable(NHF
        src/main/shapes/Figure.hpp
        src/main/shapes/Circle.hpp
        src/main/shapes/Circle.cpp
        src/main/shapes/Polygon.hpp
        src/main/shapes/Polygon.cpp
        src/main/utils/Point.cpp
        src/main/utils/Point.hpp
        src/main/shapes/Triangle.hpp
        src/main/shapes/Square.hpp
        src/main/shapes/Shapes.cpp
        src/main/shapes/Shapes.hpp
        src/main/utils/String.hpp
        src/main/controls/memtrace.cpp
        src/main/controls/memtrace.h
        src/main/utils/String.cpp
        src/main/controls/Controls.cpp
        src/main/controls/Controls.hpp
        src/main/main.cpp
        src/test/Test.cpp
        src/test/Test.hpp
)
