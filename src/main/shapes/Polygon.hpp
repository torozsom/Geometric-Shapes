/***
 * \file Polygon.hpp
 * This file contains the Polygon subclass,
 * which has a specific amount of vertices
 * that are equidistant from the middle point.
 */


#ifndef POLYGON_HPP
#define POLYGON_HPP


#include "../controls/memtrace.h"
#include "Figure.hpp"


class Polygon : public Figure {

  private:
    static constexpr unsigned MAXSIZE = 15; // maximum number of vertices
    unsigned size; // number of vertices

  protected:
    Point vertices[MAXSIZE]; // array of vertices

  public:
    Polygon();
    Polygon(const Point& p1, const Point& p2, unsigned n);
    Polygon(const Polygon& p);

    [[nodiscard]] unsigned getSize() const;
    [[nodiscard]] Point* getVertices() const;
    void setSize(unsigned n);


    void Rotate(double angle);

    [[nodiscard]] double Area() const override;

    void Log() const override;


    void Translate(const Point& v) override;
    [[nodiscard]] double Circumference() const override;
    [[nodiscard]] bool InnerPoint(const Point& p) const override;
    [[nodiscard]] bool InsideCircle(double r) const override;

    bool operator==(const Polygon& p) const;

    ~Polygon() override = default;
};


std::ostream& operator<<(std::ostream& os, const Polygon* p);


#endif // POLYGON_HPP

