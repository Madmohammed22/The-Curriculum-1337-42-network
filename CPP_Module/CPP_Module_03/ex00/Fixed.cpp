#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->FixedPointNumber = 0;
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    FixedPointNumber = copy.FixedPointNumber;
}

Fixed& Fixed::operator=(const Fixed& f) {
    std :: cout << "Copy assignment operator calle" << std :: endl;
    if (this != &f){
        FixedPointNumber = f.FixedPointNumber;
    }
    return *this;
}

Fixed :: ~Fixed(){
    std :: cout << "Destructor called" << std :: endl;
}

int Fixed :: getRawBits() const{
    std :: cout << "getRawBits member function called" << std :: endl;
    return FixedPointNumber;
}

void Fixed :: setRawBits(int const raw){
    std :: cout << "setRawBits member function called" << std :: endl;
    this->FixedPointNumber = raw;
}

