/***
 * \file Polygon.hpp
 * This file contains the Polygon subclass,
 * which has a specific amount of vertices
 * that are equidistant from the middle point.
 */

#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <iostream>
#include <cmath>
#include "Figure.hpp"
#include "memtrace.h"


class Polygon : public Figure{
    
private:
    static const unsigned MAXSIZE = 15;     // maximum number of vertices
    unsigned size;                          //number of vertices

protected:
    Point vertices[MAXSIZE];                //array of vertices

public:

    Polygon();
    Polygon(const Point& p1, const Point& p2, unsigned n);
    Polygon(const Polygon& p);

    unsigned getSize() const;
    Point* getVertices() const;
    void setSize(unsigned n);
    

    void Rotate(double angle);
    virtual double Area() const;
    virtual void Log() const;


    void Translate(const Point& v)          override;
    double Circumference() const            override;
    bool InnerPoint(const Point& p) const   override;
    bool InsideCircle(double r) const       override;

    bool operator==(const Polygon& p) const;

    virtual ~Polygon() {};
};


std::ostream& operator<<(std::ostream& os, const Polygon* p);


#endif //POLYGON_HPP

