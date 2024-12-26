#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
#include <limits>
#include "Stack.hpp"
#include <cmath>

class Stack;

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &s);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public: Stack* _stack;
    Stack* returnBasedOnCondtion(char c);

public:
    static void convert(std::string str);
    bool scanString(std::string str, ScalarConverter* scalar);
    // void pushStringToStack(std::string str, Stack* _stack);

public:
    static void displayChar(std::string, ScalarConverter* scalar);
    static void displayInt(std::string str, ScalarConverter* scalar);
    static void displayFloat(std::string str,ScalarConverter* scalar);
    static void displayDouble(std::string str, ScalarConverter* scalar);

public:
    int was_int;
    int was_float;
};

#endif