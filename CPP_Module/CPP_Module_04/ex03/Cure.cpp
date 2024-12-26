#include "Cure.hpp"
#include <iostream>

Cure::Cure() {
    this->type = "cure";
    std::cout << "[Cure] Default constructor is called" << std::endl;
}

Cure::Cure(const Cure &other) {
    this->type = other.type;
    std::cout << "[Cure] Copy constructor is called" << std::endl;
}

Cure& Cure::operator=(const Cure &other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "[Cure] Copy assignment operator is called" << std::endl;
    return *this;
}

Cure::~Cure() {
    std::cout << "[Cure] Destructor is called" << std::endl;
}

AMateria *Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}