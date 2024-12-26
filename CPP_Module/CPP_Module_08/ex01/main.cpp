#include "Span.hpp"

int main()
{
    Span sp = Span(10);
    sp.addMany();
    sp.display();
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    std::cout << "---------" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}