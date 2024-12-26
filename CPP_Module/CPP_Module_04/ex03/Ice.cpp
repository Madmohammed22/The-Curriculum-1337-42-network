#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
    std::cout << "[Ice] Default constructor is called" << std::endl;
}

Ice::Ice(const Ice &i)
{
    this->type = i.type;
    std::cout << "[Ice] Copy constructor is called" << std::endl;
}

Ice &Ice::operator=(const Ice &i)
{
    if (this != &i)
    {
        this->type = i.type;
    }
    std::cout << "[Ice] copy assignment constructor is called" << std::endl;
    return *this;
}

Ice::~Ice()
{
    std::cout << "[Ice] Distructor is called" << std::endl;
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}