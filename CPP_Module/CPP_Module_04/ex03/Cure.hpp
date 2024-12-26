#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &c);
    Cure &operator=(const Cure &c);
    ~Cure();

public:
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif