#include "A.hpp"

void A::function(){
    std::cout << "From A class" << std::endl;
}

A::~A(){
    std::cout << "[A] distructor is called" << std::endl;    
}