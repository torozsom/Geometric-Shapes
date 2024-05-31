/***
 * \file Controls.hpp
 * This file contains the function declarations
 * responsible for the menu controls and file reading.
 */

#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include <iostream>
#include <fstream>

#include "Shapes.hpp"
#include "String.hpp"
#include "Polygon.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "Triangle.hpp"
#include "memtrace.h"

void LogFile(const char* filename);
void StoreFigures(const char* filename, Shapes* data);


#endif //CONTROLS_HPP

