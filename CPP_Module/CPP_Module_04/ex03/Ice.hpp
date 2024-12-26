#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &a);
    Ice &operator=(const Ice &a);
    ~Ice();

public:
    AMateria *clone() const;
    void use(ICharacter &target);
};
#endif