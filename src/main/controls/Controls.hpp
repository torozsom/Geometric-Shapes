/***
 * \file Controls.hpp
 * This file contains the function declarations
 * responsible for the menu controls and file reading.
 */

#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include <iostream>
#include <fstream>

#include "../shapes/Shapes.hpp"
#include "../utils/String.hpp"
#include "../shapes/Polygon.hpp"
#include "../shapes/Circle.hpp"
#include "../shapes/Square.hpp"
#include "../shapes/Triangle.hpp"
#include "memtrace.h"

void LogFile(const char* filename);
void StoreFigures(const char* filename, Shapes* data);


#endif // CONTROLS_HPP

