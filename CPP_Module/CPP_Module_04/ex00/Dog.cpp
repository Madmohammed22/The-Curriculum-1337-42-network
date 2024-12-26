#include "Dog.hpp"

Dog::Dog(){
    std :: cout << "[Dog] Default constructor is called" << std :: endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& a) : Animal::Animal(a){
    std :: cout << "[Dog] Copy constructor is called" << std :: endl;
    this->type = a.type;
}

Dog& Dog::operator=(const Dog& a){
    std :: cout << "[Dog] Assigment operator is called" << std :: endl;
    if (this != &a){
        this->type = a.type;
    }
    return *this;
}

Dog::~Dog(){
    std :: cout << "[Dog] Discructor is called" <<  std ::endl;
}

void Dog::makeSound() const{
    std :: cout << "[Dog : bark] sound heard " << std :: endl;
}

std :: string Dog::getType() const {
    return this->type;
}
