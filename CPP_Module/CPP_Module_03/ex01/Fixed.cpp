#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->FixedPointNumber = 0;
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    FixedPointNumber = copy.FixedPointNumber;
}

Fixed::Fixed(const int value) {
    std::cout << "int constructor called" << std::endl;
    this->FixedPointNumber = value * std :: pow(2, this->fractional);
}

Fixed::Fixed(const float value) {
    std::cout << "float constructor called" << std::endl;
    this->FixedPointNumber = round(value * std :: pow(2, this->fractional));
}

Fixed& Fixed::operator=(const Fixed& f) {
    std :: cout << "Copy assignment operator calle" << std :: endl;
    if (this != &f)
        FixedPointNumber = f.FixedPointNumber;
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

int Fixed::toInt(void) const{ 
    return (int) FixedPointNumber / (pow(2, this->fractional));
}

float Fixed::toFloat(void) const{
    return (float) FixedPointNumber / (pow(2, this->fractional));
}

std::ostream& operator<<(std::ostream& os, const Fixed &f) {
    os << f.toFloat();
    return os;
}