/***
 * \file String.hpp
 * This file contains the String class that
 * is utilized while communicating with the
 * user and reading files contents.
 */

#ifndef STRING_HPP
#define STRING_HPP

#include "../controls/memtrace.h"
#include <cstring>
#include <iostream>

class String {

  private:
    char* data;
    unsigned len; // without \0

  public:
    String();
    String(const String& s);
    String(const char* s);


    unsigned length() const;
    char* c_str() const;


    String& operator=(const String& s);
    String& operator=(const char* text);
    String operator+(const String& rhs) const;
    char& operator[](unsigned idx) const;


    ~String();
};

String operator+(const String& s1, const String& s2);
bool operator==(const String& s, const char* text);

std::ostream& operator<<(std::ostream& os, const String& s);


#endif // STRING_HPP

