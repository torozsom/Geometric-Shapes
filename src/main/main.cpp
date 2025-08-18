/***
 * \file main.cpp
 * This is the file where the project runs
 * its main functionalities.
 */

#include "../test/Test.hpp"
#include "controls/Controls.hpp"
#include "controls/memtrace.h"
#include "shapes/Figure.hpp"
#include "shapes/Shapes.hpp"
#include "utils/Point.hpp"

int main() {

    Shapes data;
    char c;

    std::cout << "\nWelcome to my program!\n";

    do {
        std::cout
            << "\n**********************\n"
            << "Please choose from the following options:\n"
            << "1. \tPrint the content of the text file!\n"
            << "2. \tStore those figures of the text file in a heterogen "
               "collection\n"
            << " \tthat are not contained by the origin-centered unit circle.\n"
            << "3. \tPrint the properties of the stored figures!\n"
            << "4. \tEnter a (x;y) point and see which stored figure contains "
               "them!\n"
            << "5. \tTest cases\n\n"
            << "9. \tExit!\n"
            << "**********************\n\n"
            << "Please enter the appropriate number: ";

        std::cin >> c;
        std::cout << std::endl;
        Point p;

        switch (c) {
        case '1':
            LogFile("../figures.txt");
            break;

        case '2':
            data.Erase();
            StoreFigures("../figures.txt", &data);
            break;

        case '3':
            data.Log();
            break;

        case '4':
            std::cout << "Enter the coordinates:\n";
            std::cin >> p;
            std::cout << "The following figures contain the point " << p << '\n'
                      << "-------------------------------------------------\n";

            for (unsigned i = 0; i < data.getSize(); ++i)
                if (data[i]->InnerPoint(p))
                    data[i]->Log();

            std::cout
                << "-------------------------------------------------\n\n";
            break;

        case '5':
            char test;
            std::cout << "Which test would you like to run?\n\n"
                      << "\t1: Point class\n"
                      << "\t2: Circle class\n"
                      << "\t3: Polygon class\n"
                      << "\t4: Shapes class\n\n"
                      << "Enter a number(1-4): ";


            std::cin >> test;
            switch (test) {

            case '1':
                test1();
                break;

            case '2':
                test2();
                break;

            case '3':
                test3();
                break;

            case '4':
                test4();
                break;

            default:
                break;
            }

        default:
            break;
        }

    } while (c != '9' && c != EOF);

    return 0;
}

