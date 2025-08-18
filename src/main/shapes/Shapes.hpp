/***
 * \file Shapes.hpp
 * This file contains a heterogen collection
 * that stores Figure type pointers in a dynamic array.
 */


#ifndef SHAPES_HPP
#define SHAPES_HPP


#include "Figure.hpp"


class Shapes {

  private:
    Figure** pData;
    unsigned size;

    Shapes(const Shapes& s);
    Shapes& operator=(const Shapes& s);

  public:
    Shapes();

    unsigned getSize() const;

    void Add(Figure* fp);
    void Erase();
    void Log() const;

    Figure* operator[](unsigned idx);

    ~Shapes();
};

#endif // SHAPES_HPP
