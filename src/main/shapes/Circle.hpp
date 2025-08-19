/***
 * \file Circle.hpp
 * This file contains the circle subclass
 * deriving from the abstract figure class.
 */


#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include "../controls/memtrace.h"
#include "../utils/Point.hpp"
#include "Figure.hpp"


class Circle final : public Figure {

    double radius;

  public:
    Circle();
    Circle(const Point& p1, const Point& p2);
    Circle(const Circle& c);


    [[nodiscard]] double getRadius() const;
    void setRadius(double val);


    void translate(const Point& v) override;
    [[nodiscard]] double circumference() const override;
    [[nodiscard]] double area() const override;
    [[nodiscard]] bool innerPoint(const Point& p) const override;
    [[nodiscard]] bool insideCircle(double r) const override;
    void log() const override;

    bool operator==(const Circle& c) const;

    ~Circle() override = default;
};

std::ostream& operator<<(std::ostream& os, const Circle& c);

#endif // CIRCLE_HPP
