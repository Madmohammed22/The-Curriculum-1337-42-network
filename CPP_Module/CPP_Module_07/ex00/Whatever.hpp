#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

class Whatever{
    public:
        Whatever();
        Whatever(const Whatever& whatever);
        Whatever& operator=(const Whatever& whatever);
        ~Whatever();
};

// waps the values of two given arguments. Does not return anything
template <class T> void swap(T& t1, T& t2){
    T tmp;
    tmp = t1;
    t1 = t2;
    t2 = tmp;
}

/*
min: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one. 
 */

template <class T> T min(T& t1, T& t2){
    if (t1 == t2){
        std::cout << &t2 << std::endl;
        return t2;
    }
    return std::min(t1, t2);
}
/*
 max: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one 
 */

template <class T> T max(T& t1, T& t2){
    if (t1 == t2)
        return t2;
    return std::max(t1, t2);
}

#endif