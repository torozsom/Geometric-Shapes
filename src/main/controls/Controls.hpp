/***
 * \file Controls.hpp
 * This file contains the function declarations
 * responsible for the menu controls and file reading.
 */


#ifndef CONTROLS_HPP
#define CONTROLS_HPP


#include <fstream>
#include <iostream>

#include "../shapes/Circle.hpp"
#include "../shapes/Polygon.hpp"
#include "../shapes/Shapes.hpp"
#include "../shapes/Square.hpp"
#include "../shapes/Triangle.hpp"
#include "../utils/String.hpp"
#include "memtrace.h"


void logFile(const char* filename);
void storeFigures(const char* filename, Shapes* data);


#endif // CONTROLS_HPP
