/***
 * \file String.cpp
 */


#include "String.hpp"


// default ctor
String::String() {
    data = new char[1];
    data[0] = '\0';
}

// copy ctor
String::String(const String& s) : data(nullptr) { *this = s; }


// ctor: c_string to String
String::String(const char* s) : len(strlen(s)) {
    data = new char[len + 1];
    strcpy(data, s);
}


// Getter — returns the length of the current String
unsigned String::length() const { return len; }


// Getter — returns the c_string of the current String
char* String::c_str() const { return data; }


/**
 * @brief Assignment operator to copy
 * the data from another string to the
 * current one with proper memory management
 * @param s the String to be copied from
 * @return String&
 */
String& String::operator=(const String& s) {
    if (this != &s) {
        data = nullptr;
        delete[] data;
        len = s.len;
        data = new char[len + 1];
        strcpy(data, s.data);
    }
    return *this;
}


/**
 * @brief Assignment operator to create
 * String from a c_string with proper
 * memory management
 * @param text c_string
 * @return String&
 */
String& String::operator=(const char* text) {
    delete[] data;
    len = strlen(text);
    data = new char[len + 1];
    strcpy(data, text);
    return *this;
}


/**
 * @brief Concatenates the current
 * String with another String
 * @param rhs the right hand side operand
 * @return String
 */
String String::operator+(const String& rhs) const {
    String res;

    res.len = this->len + rhs.len;
    res.data = new char[res.len + 1];

    strcpy(res.data, this->data);
    strcat(res.data, rhs.data);

    res.data[res.len] = '\0';
    return res;
}


/**
 * @brief Indexing operator to access
 * the given character of the String
 * @param idx the given index
 * @return char&
 */
char& String::operator[](const unsigned idx) const {
    if (idx >= len)
        throw std::out_of_range("This string is not this long.");
    return *(data + idx);
}


// dtor
String::~String() {
    delete[] data;
    len = 0;
}


/**
 * @brief Concatenates two Strings and
 * returns a the result into another String
 * @param s1 left hand side operand
 * @param s2 right hand side operand
 * @return String
 */
String operator+(const String& s1, const String& s2) {
    const size_t len = s1.length() + s2.length();
    const auto temp = new char[len + 1];

    strcpy(temp, s1.c_str());
    strcat(temp, s2.c_str());

    String res(temp);
    delete[] temp;

    return res;
}


/**
 * @brief Checks if a String says the
 * same as a c_string
 * @param s String
 * @param text c_string
 * @return bool
 */
bool operator==(const String& s, const char* text) {
    return strcmp(s.c_str(), text) == 0;
}


/**
 * @brief Prints out the String to the
 * standard output
 * @param os right hand side operand
 * @param s String to be printed
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const String& s) {
    return os << s.c_str();
}
