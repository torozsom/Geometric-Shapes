/***
 * \file Polygon.cpp
 * Here are the definitions of the functions
 * declared in the Polygon.hpp file.
 */


#include "Polygon.hpp"
#include "../utils/String.hpp"


// default ctor
Polygon::Polygon() : size(0) {}


/**
 * @brief Constructs a new polygon, sets the middle
 * and a vertex point, and calculates the other vertices
 * @param p1 middle point
 * @param p2 vertex point
 * @param n number of vertices
 */
Polygon::Polygon(const Point& p1, const Point& p2, const unsigned n) : size(n) {
    if (n < 3 || n > MAXSIZE)
        throw std::invalid_argument(
            "You cannot set the number of vertices to this number!");
    setMiddle(p1);
    const double innerAngle = 360.0 / n;

    vertices[0] = p2;
    for (unsigned i = 1; i < size; ++i) {
        vertices[i] = vertices[i - 1];
        vertices[i].rotate(p1, innerAngle);
    }
    setPoint(vertices[0]);
}


// copy ctor
Polygon::Polygon(const Polygon& p) : Figure(p.middle, p.point), size(p.size) {
    for (unsigned i = 0; i < size; ++i)
        vertices[i] = p.vertices[i];
}


// Getter — returns the size of the polygon
unsigned Polygon::getSize() const { return size; }


Point* Polygon::getVertices() const { return const_cast<Point*>(vertices); }


// Setter — sets the size of the polygon
void Polygon::setSize(const unsigned n) { size = n; }


/**
 * @brief Rotates the current polygon
 * through the given angle
 * @param angle angle of rotation in degrees
 */
void Polygon::rotate(const double angle) {
    for (unsigned i = 0; i < size; ++i)
        vertices[i].rotate(middle, angle);
}


/**
 * @brief Translates the current polygon
 * by the given vector
 * @param v vector of translation
 */
void Polygon::translate(const Point& v) {
    for (unsigned i = 0; i < size; ++i)
        vertices[i] += v;
    middle += v;
}


// Calculates the circumference of the current polygon
double Polygon::circumference() const {
    return size * distance(vertices[0],
                           vertices[1]); // polygons have equally long sides
}


// Calculates the area of the current polygon
double Polygon::area() const {
    const double s = distance(vertices[0], vertices[1]);
    const double triangle = s * s / (4.0 * tan(M_PI / size));
    return size * triangle;
}


/**
 * @brief Checks if the current polygon
 * contains a given point
 * @param p the point to be checked
 * @return bool
 */
bool Polygon::innerPoint(const Point& p) const {
    unsigned count = 0;

    for (unsigned i = 0; i < size; ++i) {
        const Point current = vertices[i];

        if (const Point next = vertices[(i + 1) % size];
            current.y > p.y != next.y > p.y) {
            const double intersectX = (next.x - current.x) * (p.y - current.y) /
                                          (next.y - current.y) +
                                      current.x;
            if (p.x < intersectX)
                count++;
        }
    }
    return count % 2 == 1;
}


/**
 * @brief Checks if the current polygon is
 * entirely inside a circle centered at the origin
 * @param r the radius of the circle
 * @return bool
 */
bool Polygon::insideCircle(const double r) const {
    const Point origin(0.0, 0.0);

    for (unsigned i = 0; i < size; ++i)
        if (const double d = distance(origin, vertices[i]); d > r)
            return false;

    return true;
}


// Logs the properties of the current polygon
void Polygon::log() const {
    std::cout << "This polygon has " << size << " vertices: \n";
    for (unsigned i = 0; i < size; ++i)
        std::cout << vertices[i] << '\n';
    std::cout << "Its middle point is: " << middle << "\n\n";
}


bool Polygon::operator==(const Polygon& p) const {
    if (middle != p.middle)
        return false;

    for (unsigned i = 0; i < getSize(); ++i)
        if (vertices[i] != p.vertices[i])
            return false;
    return true;
}


/**
 * @brief Prints out the data of the current
 * polygon to the standard output
 * @param os left hand side operand
 * @param p the polygon to be printed (rhs)
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Polygon* p) {
    String type;
    if (p->getSize() == 3)
        type = "triangle";
    else if (p->getSize() == 4)
        type = "square";
    else
        type = "polygon";

    os << std::fixed << std::setprecision(2) << "This " << type
       << " has the following " << p->getSize() << " vertices: \n";

    for (unsigned i = 0; i < p->getSize(); ++i)
        os << p->getVertices()[i];

    os << "Its middle point is: " << p->getMiddle()
       << "It has an area of: " << p->area() << '\n'
       << "And its circumference is: " << p->circumference() << '\n';

    return os;
}
