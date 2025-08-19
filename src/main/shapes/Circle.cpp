/***
 * \file Circle.cpp
 * This file contains the definitions
 * for the member functions declared in Circle.hpp.
 */


#include "Circle.hpp"


// default ctor
Circle::Circle() : radius(0.0) {}

// ctor
Circle::Circle(const Point& p1, const Point& p2)
    : Figure(p1, p2), radius(distance(p1, p2)) {}

// copy ctor
Circle::Circle(const Circle& c) : Figure(c.middle, c.point), radius(c.radius) {}


// Getter — returns the radius of the current circle
double Circle::getRadius() const { return radius; }


// Setter — assigns the double parameter to the radius
void Circle::setRadius(const double r) { radius = r; }


/**
 * @brief Translates the current circle
 * by the given vector
 * @param v vector of translation
 */
void Circle::translate(const Point& v) {
    middle += v;
    point += v;
}


// Calculates the circumference of the current circle
double Circle::circumference() const { return 2 * radius * M_PI; }


// Calculates the circumference of the current circle
double Circle::area() const { return radius * radius * M_PI; }


/**
 * @brief Checks if the currenct circle
 * contains the given point
 * @param p the point to be checked
 * @return bool
 */
bool Circle::innerPoint(const Point& p) const {
    return distance(middle, p) <= radius;
}


/**
 * @brief Checks if the current circle
 * is inside a circle centered at the origin
 * @param r the radius of the origin centered circle
 * @return bool
 */
bool Circle::insideCircle(const double r) const {
    return distance(Point(0.0, 0.0), middle) + radius <= r;
}


// Logging the properties of the current circle
void Circle::log() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The circle's radius is: " << radius << "\n"
              << "Middle point: " << middle << '\n'
              << "Point on the circumference: " << point << "\n\n";
}


bool Circle::operator==(const Circle& c) const {
    return middle == c.middle && point == c.point;
}


/**
 * @brief Prints out the data of the current
 * circle to the standard output
 * @param os left hand side operand
 * @param c the circle to be printed out
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Circle& c) {
    std::cout << std::fixed << std::setprecision(2);
    os << "The radius of the circle is: " << c.getRadius() << "\n"
       << "The circle's circumference is: " << c.circumference() << "\n"
       << "The circle's area is: " << c.area() << "\n"
       << "The circle's middle point is: " << c.getMiddle() << "\n\n";
    return os;
}


/**
 * @brief Reads in a circle from the
 * user through the standard input
 * @param is left hand side operand
 * @param c reference to be read into
 * @return std::istream&
 */
std::istream& operator>>(std::istream& is, Circle& c) {

    Point mid, point;

    std::cout << "Set the middle point: \n";
    is >> mid;

    std::cout << "Set the point on the circumference: \n";
    is >> point;

    c = Circle(mid, point);

    return is;
}
