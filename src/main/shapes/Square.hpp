/***
 * \file Square.hpp
 * This file contains the definition of
 * a special polygon: the square.
 */


#ifndef SQUARE_HPP
#define SQUARE_HPP


#include "../controls/memtrace.h"
#include "Polygon.hpp"


class Square final : public Polygon {

  public:
    Square() = default;
    Square(const Point& p1, const Point& p2) : Polygon(p1, p2, 4) {}
    Square(const Square& s) : Polygon(s.middle, s.point, 4) {}


    [[nodiscard]]
    double Area() const override {
        return pow(Distance(vertices[0], vertices[1]), 2);
    }


    void Log() const override {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "The square's vertices: \n";
        for (unsigned i = 0; i < 4; ++i)
            std::cout << vertices[i] << '\n';
        std::cout << "It's middle point is: " << middle << "\n\n";
    }


    ~Square() override = default;
};

#endif // SQUARE_HPP

