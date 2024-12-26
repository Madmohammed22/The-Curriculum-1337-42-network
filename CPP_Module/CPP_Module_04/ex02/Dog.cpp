#include "Dog.hpp"

// Dog::Dog(){
Dog::Dog() : brain(new Brain()){
    std :: cout << "[Dog] Default constructor is called" << std :: endl;
    this->type = "Dog";
}

// Dog::Dog(const Dog& a) : brain(a.brain){
Dog::Dog(const Dog& a) : brain(new Brain(*a.brain)){
    std :: cout << "[Dog] Copy constructor is called" << std :: endl;
    this->type = a.type;
}

Dog& Dog::operator=(const Dog& a){
    if (this == &a){
        return *this;
    }
    // clean up an existing resources 
    delete brain;
    this->brain = new Brain(*a.brain);
    this->type = a.type;
    std :: cout << "[Dog] Assigment operator is called" << std :: endl;
    return *this;
}

Dog::~Dog(){
    std :: cout << "[Dog] Discructor is called" <<  std ::endl;
    delete this->brain;
}

void Dog::makeSound() const{
    std :: cout << "[Dog : bark] sound heard " << std :: endl;
}

std :: string Dog::getType() const {
    return this->type;
}
