#include <iostream>
#include "Whatever.hpp"

template <class T>
T add(T &t1, T &t2)
{
    T result = t1 + t2;
    return result;
}

template <class T>
T returnData(T &data)
{
    return data;
}

template <class T>
void displayData(T &data)
{
    std::cout << data << std::endl;
}

int main__()
{
    int a = 10;
    int b = 10;
    int result = min(a, b);
    std::cout << &b << std::endl;
    // std::cout << &a << std::endl;
    std::cout << result << std::endl;

    return 0;
}

int main(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    return 0;
}

/*
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2 
 */