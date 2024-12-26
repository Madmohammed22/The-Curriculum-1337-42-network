#include "Character.hpp"

Character::Character() : name("")
{
    initializeInventory();
    std::cout << "[Character] Default constructor is called" << std::endl;
}

Character::Character(std::string const &name) : name(name)
{
    initializeInventory();
    std::cout << "[Character] Parametrize constructor is called" << std::endl;
}

Character::Character(const Character &other) : name(other.name)
{
    initializeInventory();
    for (int i = 0; i < 4; ++i)
    {
        if (other.inventory[i])
        {
            inventory[i] = other.inventory[i]->clone();
        }
        else
        {
            inventory[i] = NULL;
        }
    }
    std::cout << "[Character] Copy constructor is called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
    if (this == &other)
    {
        return *this;
    }
    for (int i = 0; i < 4; ++i)
    {
        delete inventory[i];
    }
    name = other.name;
    for (int i = 0; i < 4; ++i)
    {
        if (other.inventory[i])
        {
            inventory[i] = other.inventory[i]->clone();
        }
        else
        {
            inventory[i] = NULL;
        }
    }
    std::cout << "[Character] copy assignment constructor is called" << std::endl;
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        delete inventory[i];
    }
    std::cout << "[Character] Distructor is called" << std::endl;
}

const std::string &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        inventory[idx]->use(target);
    }
}

void Character::initializeInventory() {

    for (int i = 0; i < 4; ++i) {

        inventory[i] = NULL;

    }
}