#include "Animal.hpp"

Animal::Animal(){
    std :: cout << "[Animal] Default constructor is called" << std :: endl;
    this->type = "Animal";
}

Animal::Animal(const Animal& a){
    std :: cout << "[Animal] Copy constructor is called" << std :: endl;
    this->type = a.type;
}

Animal& Animal::operator=(const Animal& a){
    std :: cout << "[Animal] Assigment operator is called" << std :: endl;
    if (this != &a){
        this->type = a.type;
    }
    return *this;
}

Animal::~Animal(){
    std :: cout << "[Animal] Discructor is called" <<  std ::endl;
}

void Animal::makeSound() const {
    std :: cout << "[Animal] sound heard" << std :: endl;
}

std :: string Animal::getType() const{
    return this->type;
}