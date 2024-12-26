#ifndef STACK_HPP
#define STACK_HPP

#include <limits>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

class Stack
{
private:
    char ch[__INT_MAX__];
    int top;

public:
    Stack();
    Stack(Stack& s);
    Stack& operator=(Stack& other);
    ~Stack();

public:
    void push(char c);
    char pop();
    char peek();
    Stack* cloneStack(Stack *_stack);

public:
    int getTop();
};

#endif

// float inf = std::numeric_limits<float>::infinity();
    // float n = .0;
    // std::cout << __INT_MAX__ << std::endl;