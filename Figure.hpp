/*** 
 * \file Figures.hpp
 * This file contains the abstract class
 * for the 2D geometric figures in general.
 */

#ifndef FIGURE_HPP
#define FIGURE_HPP


#include "Point.hpp"
#include "memtrace.h"


class Figure{

protected:
    Point middle;
    Point point;

public:

    Figure() : middle(), point() {}
    Figure(const Point& p1, const Point& p2) : middle(p1), point(p2) {}


    void setMiddle(const Point& p) { middle = p; };
    void setPoint(const Point& p) { point = p; };


    Point getMiddle() const { return middle; };
    Point getPoint() const { return point; };


    virtual void Translate(const Point& v)          = 0;
    virtual double Circumference() const            = 0;
    virtual double Area() const                     = 0;
    virtual bool InnerPoint(const Point& p) const   = 0;
    virtual bool InsideCircle(double r) const       = 0;
    virtual void Log() const                        = 0;

    
    virtual ~Figure() {}
}; 


#endif //FIGURE_HPP

