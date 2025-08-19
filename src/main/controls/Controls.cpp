/***
 * \file Controls.cpp
 * This file contains the function definitions
 * needed to converse with the program's user.
 */


#include "Controls.hpp"


/**
 * @brief Logs the content of the given text file
 * @param filename the path of the text file
 */
void logFile(const char* filename) {
    if (std::ifstream file(filename); !file.is_open())
        std::cerr << "Failed to open file.\n";
    else {
        std::cout << "Content of the file:\n"
                  << "--------------------------------\n";
        constexpr unsigned MAX_LEN = 256;
        char buffer[MAX_LEN];

        while (file.getline(buffer, MAX_LEN)) {
            String line(buffer);
            std::cout << line << '\n';
        }
        std::cout << "--------------------------------\n\n";
        file.close();
    }
}


/**
 * @brief Stores the figures recognized in the
 * text file in a heterogen collection
 * @param filename the path of the text file
 * @param data the pointer to the heterogen collection
 */
void storeFigures(const char* filename, Shapes* data) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file!");

    constexpr unsigned MAX_LEN = 256;
    char line[MAX_LEN];
    while (file.getline(line, MAX_LEN)) {

        char* temp[3];
        int i = 0;

        temp[i] = strtok(line, ",");
        while (temp[i] != nullptr && i < 2)
            temp[++i] = strtok(nullptr, ",");

        unsigned vertices;
        double mx, my, px, py;

        const int res1 = sscanf(temp[0], "%*[^0-9]%u", &vertices);
        sscanf(temp[1], " (%lf;%lf)", &mx, &my);
        sscanf(temp[2], " (%lf;%lf)", &px, &py);

        String type(temp[0]);
        Point middle(mx, my);
        Point point(px, py);

        if (res1 == 1)
            if (Figure* fp = new Polygon(middle, point, vertices);
                !fp->insideCircle(1.0))
                data->add(fp);

        if (type == "Circle")
            if (Figure* fp = new Circle(middle, point); !fp->insideCircle(1.0))
                data->add(fp);

        if (type == "Square")
            if (Figure* fp = new Square(middle, point); !fp->insideCircle(1.0))
                data->add(fp);

        if (type == "Triangle")
            if (Figure* fp = new Triangle(middle, point);
                !fp->insideCircle(1.0))
                data->add(fp);
    }

    file.close();
    std::cout << "Successfully stored!\n" << "-----------------------\n\n";
}
