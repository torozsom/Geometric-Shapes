/***
 * \file Test.cpp
 * This file contains the test cases of the project.
 */


#include "Test.hpp"


/**
 * @brief Checks if a given vector can be
 * rotated by a given angle, and if the
 * operator overloads are functional
 */
void test1() {

    std::cout << "\nTesting the functionality of the Point class:\n\n";


    //  ***ROTATION OF A VECTOR***


    Point V0(5, 6);
    const Point center(4, 1);
    const Point rotated(-1.0, 2.0);


    std::cout
        << "1. Rotation of a vector around a given center by a given angle: \n"
        << "\t Let the vector be " << V0 << " and the center of rotation "
        << center << ".\n"
        << "\t Expected: \t" << rotated << '\n';

    V0.rotate(center, 90);
    std::cout << "\t Actual: \t" << V0 << "\n";


    if (V0 == rotated)
        std::cout << "Successfully rotated!\n\n\n";
    else
        std::cerr << "Unsuccessful rotation!\n\n\n";


    //  ***ADDITION OF VECTORS***


    const Point v1(1, 2), v2(3, 4), sum = v1 + v2, sub = v2 - v1;
    const Point res1(4, 6), res2(2, 2);


    std::cout << "2. Addition of vectors:\n"
              << "\t Let the vectors be " << v1 << " and the other " << v2
              << "\n"
              << "\t Expected: \t" << res1 << '\n';
    std::cout << "\t Actual: \t" << sum << "\n";


    if (sum == res1)
        std::cout << "Successfully added!\n\n\n";
    else
        std::cerr << "Unsuccessful addition!\n\n\n";


    //  ***SUBTRACTION OF VECTORS***


    std::cout << "3. Subtraction of vectors:\n"
              << "\t Let the vectors be " << v2 << " and the other " << v1
              << "\n"
              << "\t Expected: \t" << res2 << '\n';
    std::cout << "\t Actual: \t" << sub << "\n";

    if (sub == res2)
        std::cout << "Successfully subtracted!\n\n\n";
    else
        std::cerr << "Unsuccessful subtraction!\n\n\n";


    //  ***DISTANCE OF TWO POINTS


    std::cout << "5. Distance of two points:\n"
              << "\t Let the points be " << v1 << " and the other " << v2
              << "\n"
              << "\t Expected: \t" << sqrt(8) << '\n';
    std::cout << "\t Actual: \t" << distance(v1, v2) << "\n";

    if (dEqual(distance(v1, v2), sqrt(8)))
        std::cout << "Correct distance!\n\n\n";
    else
        std::cerr << "Incorrect distance!\n\n\n";
}


/**
 * @brief Checks the correct functionality
 * of the circle class's member functions
 */
void test2() {

    std::cout << "\nTesting the functionality of the circle class:\n\n\n";


    //  ***TRANSLATION***


    const Point V0(6.55, 8.75);
    Circle C0(Point(5.40, 8.3), Point(7.22, 9.78));
    const Circle res(Point(11.95, 17.05), Point(13.77, 18.53));


    std::cout << "1. Translating a circle by a given vector:\n\n"
              << "Let the vector be: " << V0 << '\n'
              << "Current properties:\n";
    C0.log();

    std::cout << "\nExpected: \n";

    res.log();
    C0.translate(V0);

    std::cout << "\nActual: \n";
    C0.log();
    std::cout << '\n';

    if (C0 == res)
        std::cout << "Successful translation!\n\n";
    else
        std::cerr << "Unsuccessful translation!\n\n";


    //  ***INNER POINT***


    const Point P1(6.1, 8.5);
    const Circle C1(Point(5.05, 8.35), Point(8.82, 10.68));

    std::cout << "2. Checking inner point: \n\n"
              << "Let the point be: " << P1 << '\n';

    C1.log();
    const bool inner = C1.innerPoint(P1);

    std::cout << "Expected: \t true\n"
              << "Actual: \t " << std::boolalpha << inner << '\n';

    if (inner)
        std::cout << "Correct answer!\n\n";
    else
        std::cerr << "Incorrect answer!\n\n";


    //  ***INSIDE A CIRCLE***


    const Circle C2(Point(2.34, 3.89), Point(4.81, 5.75));

    std::cout << "3. Cheking if a given circle is inside another circle \n"
              << "that is centered at the origin and has a radius R.\n\n"
              << "Let R be 8.76\n";
    C2.log();

    const bool inside = C2.insideCircle(8.76);

    std::cout << "Expected: \t true\n"
              << "Actual: \t " << std::boolalpha << inside << '\n';

    if (inside)
        std::cout << "Correct answer!\n\n";
    else
        std::cerr << "Incorrect answer!\n\n";
}


/**
 * @brief Checks the correct functionality
 * of the polygon class's member functions,
 * so in the mean time checks the correctness
 * of the subclasses triangle and square
 */
void test3() {

    std::cout << "\nTesting the functionality of the polygon class:\n\n\n";


    //  ***TRANSLATION***


    const Point V0(6.55, 8.75);
    Polygon Poly0(Point(5.40, 8.3), Point(7.22, 9.78), 5);

    const Polygon res0(Point(11.95, 17.05), Point(13.77, 18.53), 5);

    std::cout << "1. Translating a polygon by a given vector:\n\n"
              << "Let the vector be: " << V0 << '\n'
              << "Current properties:\n";

    Poly0.log();

    std::cout << "\nExpected: \n";
    res0.log();

    Poly0.translate(V0);
    std::cout << "\nActual: \n";
    Poly0.log();

    if (res0 == Poly0)
        std::cout << "Succesful translation!\n\n";
    else
        std::cerr << "Unsuccesful translation!\n\n";


    //  ***ROTATION***


    Polygon Poly1(Point(0, 0), Point(2, 0), 6);
    const Polygon res1(Point(0, 0), Point(0, 2), 6);

    std::cout << "2. Rotating a polygon by a given angle: \n\n"
              << "Let the angle be 90 degrees.\n";

    Poly1.log();

    std::cout << "Expected: \n";
    res1.log();
    std::cout << "Actual: \n";

    Poly1.rotate(90);
    Poly1.log();

    if (res1 == Poly1)
        std::cout << "Succesful rotation!\n\n";
    else
        std::cerr << "Unsuccesful rotation!\n\n";


    //  ***INNER POINT***


    const Point P2(4.3, 5.7);
    const Polygon Poly2(Point(2.5, 3.8), Point(8.8, 9.3), 7);

    std::cout << "3. Checking inner point: \n\n"
              << "Let the point be: " << P2 << '\n';

    Poly2.log();
    const bool inner = Poly2.innerPoint(P2);

    std::cout << "Expected: true\n"
              << "Actual:\t " << std::boolalpha << inner << '\n';

    if (inner)
        std::cout << "Correct answer!\n\n";
    else
        std::cerr << "Incorrect answer!\n\n";


    //  ***INSIDE A CIRCLE***


    const Polygon Poly3(Point(2.6, 6.8), Point(4.3, 5.9), 8);

    std::cout << "4. Cheking if a given polygon is inside a circle \n"
              << "that is centered at the origin and has a radius R.\n\n"
              << "Let R be 10.45\n";
    Poly3.log();

    const bool inside = Poly3.insideCircle(10.45);
    std::cout << "Expected: true\n"
              << "Actual: " << std::boolalpha << inside << '\n';

    if (inside)
        std::cout << "Correct answer!\n\n";
    else
        std::cerr << "Incorrect answer!\n\n";
}


/**
 * @brief Checks the correct functionality
 * of the heterogen collection's (shapes class)
 * member functions
 */
void test4() {

    std::cout << "\nTesting the functionality of the heterogen collection.\n"
              << "Let's create a container: \n";

    Shapes container;
    container.log();
    std::cout << "\nSo let's add some figures to the container: \n";

    container.add(new Circle(Point(6.7, 5.5), Point(3.4, 2.2)));
    container.add(new Polygon(Point(3.7, 5.9), Point(6.6, 8.4), 7));
    container.add(new Triangle(Point(4.5, 6.1), Point(2.5, 3.4)));
    container.add(new Square(Point(3.2, 4.5), Point(7.6, 7.1)));

    container.log();
    const unsigned size = container.getSize();

    std::cout << "Expected size: 4\n"
              << "Actual size: " << size << '\n';

    if (size == 4)
        std::cout << "Correct Add() method!\n\n";
    else
        std::cout << "Incorrect Add() method!\n\n";


    std::cout << "Let's now erase the content of the container!\n";
    container.erase();
    const unsigned erased = container.getSize();

    std::cout << "Expected size: 0\n"
              << "Actual size: " << erased << '\n';

    if (erased == 0)
        std::cout << "Correct Erase() method!\n\n";
    else
        std::cout << "Incorrect Erase() method!\n\n";
}


/**
 * The String class I use is very similar to the one
 * we implemented earlier during the semester, so
 * I set aside testing its functionality.
 */
