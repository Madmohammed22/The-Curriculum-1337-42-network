#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class Animal {
public:
    Animal();
    Animal(const Animal& a);
    Animal& operator=(const Animal& a);
    virtual ~Animal();
    virtual void makeSound() const;
    virtual std::string getType() const;

protected:
    std::string type;
};

#endif