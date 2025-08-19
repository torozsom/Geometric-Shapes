/***
 * \file Figure.hpp
 * This file contains the abstract class
 * for the 2D geometric figures in general.
 */


#ifndef FIGURE_HPP
#define FIGURE_HPP


#include "../utils/Point.hpp"


class Figure {

  protected:
    Point middle;
    Point point;


  public:
    Figure() = default;
    Figure(const Point& p1, const Point& p2) : middle(p1), point(p2) {}


    void setMiddle(const Point& p) { middle = p; };
    void setPoint(const Point& p) { point = p; };


    [[nodiscard]] Point getMiddle() const { return middle; };
    [[nodiscard]] Point getPoint() const { return point; };


    virtual void translate(const Point& v) = 0;
    [[nodiscard]] virtual double circumference() const = 0;
    [[nodiscard]] virtual double area() const = 0;
    [[nodiscard]] virtual bool innerPoint(const Point& p) const = 0;
    [[nodiscard]] virtual bool insideCircle(double r) const = 0;
    virtual void log() const = 0;


    virtual ~Figure() = default;
};


#endif // FIGURE_HPP
