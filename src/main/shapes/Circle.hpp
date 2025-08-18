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


class Circle : public Figure {

  private:
    double radius;

  public:
    Circle();
    Circle(const Point& p1, const Point& p2);
    Circle(const Circle& c);


    double getRadius() const;
    void setRadius(double val);


    void Translate(const Point& v) override;
    double Circumference() const override;
    double Area() const override;
    bool InnerPoint(const Point& p) const override;
    bool InsideCircle(double r) const override;
    void Log() const override;

    bool operator==(const Circle& c) const;

    ~Circle() {}
};

std::ostream& operator<<(std::ostream& os, const Circle& c);

#endif // CIRCLE_HPP

