/***
 * \file Point.hpp
 * In this file, a Point structure is declared
 * so that we can create Figures on the 2D plane.
 */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include "memtrace.h"


/// For tests
inline bool dEqual(double d1, double d2, double tolerance = 1e-3){
    return std::fabs(d1-d2) < tolerance;
}



struct Point{

    double x;    
    double y;    


    Point();
    Point(double x, double y);
    Point(const Point& p);      

    void Rotation(const Point& center, double angle);


    Point& operator=(const Point& p);
    Point operator-(const Point& p) const;
    Point& operator-=(const Point& p);
    Point operator+(const Point& p) const ;
    Point& operator+=(const Point& p);
    bool operator ==(const Point& p) const;

    ~Point();
};

std::ostream& operator<<(std::ostream& os, const Point& p);
std::istream& operator>>(std::istream& is, Point& p);

double Distance(const Point& p1, const Point& p2);

#endif //POINT_HPP

