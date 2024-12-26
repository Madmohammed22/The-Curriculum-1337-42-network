#include "Whatever.hpp"

Whatever::Whatever(){
    std::cout << "[Whatever] Default constructor is called" << std::endl;
}

Whatever::Whatever(const Whatever& whatever){
    (void)whatever;
}

Whatever& Whatever::operator=(const Whatever& whatever){
    if (this == &whatever)
        return *this;

    return *this;
}

Whatever::~Whatever(){
    std::cout << "[Whatever] Distructor is called" << std::endl;
}