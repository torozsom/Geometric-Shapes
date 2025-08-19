/***
 * \file Point.hpp
 * In this file, a Point structure is declared
 * so that we can create Figures on the 2D plane.
 */


#ifndef POINT_HPP
#define POINT_HPP


#include "../controls/memtrace.h"
#include <cmath>
#include <iomanip>


/// For tests
inline bool dEqual(const double d1, const double d2,
                   const double tolerance = 1e-3) {
    return std::fabs(d1 - d2) < tolerance;
}


struct Point {

    double x;
    double y;


    Point();
    Point(double x, double y);
    Point(const Point& p);

    void rotate(const Point& center, double angle);


    Point& operator=(const Point& p);
    Point operator-(const Point& p) const;
    Point& operator-=(const Point& p);
    Point operator+(const Point& p) const;
    Point& operator+=(const Point& p);
    bool operator==(const Point& p) const;

    ~Point();
};

std::ostream& operator<<(std::ostream& os, const Point& p);
std::istream& operator>>(std::istream& is, Point& p);

double distance(const Point& p1, const Point& p2);

#endif // POINT_HPP
