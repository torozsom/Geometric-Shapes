/***
 * \file Point.cpp
 * Here are the definitions for the
 * functions declared in Point.hpp.
 */


#include "Point.hpp"


// default ctor
Point::Point() : x(0), y(0) {}

// ctor
Point::Point(const double x, const double y) : x(x), y(y) {}

// copy ctor
Point::Point(const Point& p) = default;


/**
 * @brief Rotates the current point around
 * another through the given angle
 * @param center the center point of rotation
 * @param angle the angle of rotation in degrees
 */
void Point::Rotation(const Point& center, const double angle) {
    const double radians = angle * M_PI / 180.0;

    const double cosTheta = cos(radians);
    const double sinTheta = sin(radians);

    const double newX = x - center.x;
    const double newY = y - center.y;

    x = center.x + newX * cosTheta - newY * sinTheta;
    y = center.y + newX * sinTheta + newY * cosTheta;
}


// Assignment operator
Point& Point::operator=(const Point& p) = default;


/**
 * @brief Subtracts a point from the current
 * one and returns it as a new point
 * @param p right hand side operand
 * @return Point
 */
Point Point::operator-(const Point& p) const { return {x - p.x, y - p.y}; }


/**
 * @brief Subtracts another point from
 * the current point and saves the changes
 * @param p right hand side operand
 * @return Point&
 */
Point& Point::operator-=(const Point& p) {
    x -= p.x;
    y -= p.y;
    return *this;
}


/**
 * @brief Adds another point to the current
 * one and returns it as a new point
 * @param p right hand side operand
 * @return Point
 */
Point Point::operator+(const Point& p) const { return {x + p.x, y + p.y}; }


/**
 * @brief Adds a point to the current
 * point and saves the changes
 * @param p
 * @return Point&
 */
Point& Point::operator+=(const Point& p) {
    x += p.x;
    y += p.y;
    return *this;
}


bool Point::operator==(const Point& p) const {
    return dEqual(x, p.x) && dEqual(y, p.y);
}

// dtor
Point::~Point() = default;


/**
 * @brief Prints out a point to the
 * standard output
 * @param os left hand side operand
 * @param p the point to be printed (rhs)
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << std::fixed << std::setprecision(2) << "(" << p.x << ";" << p.y
              << ")";
}


/**
 * @brief Reads in a point from the user
 * through the standard input
 * @param is left hand side operand
 * @param p the reference to be read into
 * @return std::istream&
 */
std::istream& operator>>(std::istream& is, Point& p) {
    double x, y;

    std::cout << "x-coordinate: ";
    is >> x;
    std::cout << "y-coordinate: ";
    is >> y;
    std::cout << '\n';

    p = Point(x, y);
    return is;
}


/**
 * @brief Calculates the distance between
 * two points on the 2D-plane
 * @param p1 starting point
 * @param p2 ending point
 * @return double
 */
double Distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

