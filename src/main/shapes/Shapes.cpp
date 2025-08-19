/***
 * \file Shapes.cpp
 * Here are the definitions of the fucntions
 * declared in the Shapes.hpp file.
 */


#include "Shapes.hpp"


// default ctor
Shapes::Shapes() : size(0) {
    pData = new Figure*[1];
    pData[0] = nullptr;
}


// Getter — returns the size of the current heterogen collection
unsigned Shapes::getSize() const { return size; }


/**
 * @brief Appends the array of the heterogen
 * collection with a Figure pointer
 * @param fp the pointer of the object to be added
 */
void Shapes::add(Figure* fp) {
    if (fp != nullptr) {
        const auto temp = new Figure*[size + 1];
        for (unsigned i = 0; i < size; ++i)
            temp[i] = pData[i];
        delete[] pData;
        pData = temp;
        pData[size++] = fp;
    }
}


/**
 * @brief Empties the array of the heterogen
 * collection — deletes its elements
 */
void Shapes::erase() {
    if (size != 0) {
        for (unsigned i = 0; i < size; ++i) {
            delete pData[i];
            pData[i] = nullptr;
        }
        size = 0;
    }
}


// Logs the properties of the current heterogen collection
void Shapes::log() const {
    if (size == 0)
        std::cout << "There is nothing in the array yet.\n\n";
    else {
        std::cout << "_________________________________\n\n";
        for (unsigned i = 0; i < size; ++i) {
            std::cout << '(' << i + 1 << ". element) \n";
            pData[i]->log();
        }
        std::cout << "_________________________________\n\n";
    }
}

/**
 * @brief Index operator for the heterogen
 * collection to acces the elements of its array
 * @param idx the given index
 * @return Figure*
 */
Figure* Shapes::operator[](const unsigned idx) const { return pData[idx]; }


// dtor
Shapes::~Shapes() {
    for (unsigned i = 0; i < size; ++i)
        delete pData[i];
    delete[] pData;
};
