#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter{

public:
    Character();
    Character(std::string const& name);
    Character(const Character &c);
    Character &operator=(const Character &c);
    virtual ~Character();
public:
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
    void initializeInventory();
protected:
    std::string name;
    AMateria* inventory[4];
};

#endif
