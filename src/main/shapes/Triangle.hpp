/***
 * \file Triangle.hpp
 * This file contains the definition of
 * a special polygon: the equilateral triangle.
 */


#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP


#include "../controls/memtrace.h"
#include "Polygon.hpp"


class Triangle : public Polygon {

  public:
    Triangle() : Polygon() {}
    Triangle(const Point& p1, const Point& p2) : Polygon(p1, p2, 3) {}
    Triangle(const Triangle& t) : Polygon(t.middle, t.point, 3) {}


    double Area() const override {
        return (pow(Distance(vertices[0], vertices[1]), 2) * sqrt(3) / 4.0);
    }


    void Log() const override {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "The triangle's vertices: \n";
        for (unsigned i = 0; i < 3; ++i)
            std::cout << vertices[i] << '\n';
        std::cout << "It's middle point is: " << middle << "\n\n";
    }

    ~Triangle() override {};
};

#endif // TRIANGLE_HPP

