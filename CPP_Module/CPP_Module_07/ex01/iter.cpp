#include "iter.hpp"

Iter::Iter(){
    std::cout << "[Iter] Default constructor is called" << std::endl;
}

Iter::Iter(const Iter& iter){
    (void)iter;
}

Iter& Iter::operator=(const Iter& iter){
    if (this == &iter)
        return *this;

    return *this;
}

Iter::~Iter(){
    std::cout << "[Iter] Distructor is called" << std::endl;
}

