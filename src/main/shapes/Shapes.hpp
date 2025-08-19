/***
 * \file Shapes.hpp
 * This file contains a heterogen collection
 * that stores Figure type pointers in a dynamic array.
 */


#ifndef SHAPES_HPP
#define SHAPES_HPP


#include "Figure.hpp"


class Shapes {

    Figure** pData;
    unsigned size;

    Shapes(const Shapes& s);
    Shapes& operator=(const Shapes& s);


  public:
    Shapes();

    [[nodiscard]] unsigned getSize() const;

    void add(Figure* fp);
    void erase();
    void log() const;

    Figure* operator[](unsigned idx) const;

    ~Shapes();
};

#endif // SHAPES_HPP
