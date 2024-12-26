#include "AMateria.hpp"

AMateria::AMateria(){
    std::cout << "[AMateria] Default constructor is called" << std::endl;
    this->type = this->getType();
}

AMateria::AMateria(const AMateria& other){
    std::cout << "[AMateria] Copy constructor is called" << std::endl;
    this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other){
    if (this != &other){
        this->type = other.type;
    }
    std::cout << "[AMateria] Assignment operator is called" << std::endl;
    return *this;
}

AMateria::~AMateria(){
    std::cout << "[AMateria] Distructor is called" << std::endl;
}

AMateria::AMateria(std::string const &type){
    std::cout << "[AMateria] Parametrize constructor is called" << std::endl;
    this->type = type;
}

std::string const& AMateria::getType() const{
    return this->type;
}

void AMateria::use(ICharacter &target){
    std::cout << "Using Materia of type: " << target.getName() << std::endl;
}