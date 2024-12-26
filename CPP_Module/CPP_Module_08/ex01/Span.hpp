#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

class Span
{

public:
    Span();
    Span(unsigned int N);
    Span(const Span &Init);
    Span &operator=(const Span &Init);
    ~Span();

public:

    std::vector<int> buffer;
    unsigned int count;
    unsigned int reserve;
    void addNumber(int data);
    unsigned int longestSpan();
    unsigned int shortestSpan();
    void display();
    void addMany();
};

#endif