#include "Cat.hpp"

Cat::Cat(){
    std :: cout << "[Cat] Default constructor is called" << std :: endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& a) : Animal::Animal(a){
    std :: cout << "[Cat] Copy constructor is called" << std :: endl;
    this->type = a.type;
}

Cat& Cat::operator=(const Cat& a){
    std :: cout << "[Cat] Assigment operator is called" << std :: endl;
    if (this != &a){
        this->type = a.type;
    }
    return *this;
}

Cat::~Cat(){
    std :: cout << "[Cat] Discructor is called" <<  std ::endl;
}

void Cat::makeSound() const{
    std :: cout << "[Cat : meows] sound heard " << std :: endl;
}

std :: string Cat::getType() const{
    return this->type;
}
