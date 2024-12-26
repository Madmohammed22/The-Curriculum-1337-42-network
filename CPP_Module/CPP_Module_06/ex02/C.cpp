#include "C.hpp"

void C::function(){
    std::cout << "From C class" << std::endl;
}

C::~C(){
    std::cout << "[C] distructor is called" << std::endl;
}