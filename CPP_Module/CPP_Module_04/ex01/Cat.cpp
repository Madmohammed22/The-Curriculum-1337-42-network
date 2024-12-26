#include "Cat.hpp"

// Cat::Cat() {
Cat::Cat() : brain(new Brain()){
    this->type = "Cat";
    std :: cout << "[Cat] Default constructor is called" << std :: endl;
}

// Cat::Cat(const Cat& a) : brain(a.brain){ // copyies the pointer.
Cat::Cat(const Cat& a) : brain(new Brain(*a.brain)){
    this->type = a.type;
    std :: cout << "[Cat] Copy constructor is called" << std :: endl;
}

Cat& Cat::operator=(const Cat& a) {
    if (this != &a) {
        delete brain;
        brain = new Brain(*a.brain);
        this->type = a.type;
    }
    std::cout << "[Cat] Assignment operator is called" << std::endl;
    return *this;
}

Cat::~Cat(){
    std :: cout << "[Cat] Discructor is called" <<  std ::endl;
    delete this->brain;
}

void Cat::makeSound() const{
    std :: cout << "[Cat : meows] sound heard " << std :: endl;
}

std :: string Cat::getType() const{
    return this->type;
}

Brain* Cat::getBrain() const {
    return brain;
}