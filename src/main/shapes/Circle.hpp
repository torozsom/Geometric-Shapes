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

  private:
    double radius;

  public:
    Circle();
    Circle(const Point& p1, const Point& p2);
    Circle(const Circle& c);


    [[nodiscard]] double getRadius() const;
    void setRadius(double val);


    void Translate(const Point& v) override;
    [[nodiscard]] double Circumference() const override;
    [[nodiscard]] double Area() const override;
    [[nodiscard]] bool InnerPoint(const Point& p) const override;
    [[nodiscard]] bool InsideCircle(double r) const override;
    void Log() const override;

    bool operator==(const Circle& c) const;

    ~Circle() override = default;
};

std::ostream& operator<<(std::ostream& os, const Circle& c);

#endif // CIRCLE_HPP

