#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name), weapon(NULL)
{
}

HumanB::~HumanB()
{
    std ::cout << "HumanB destroyed" << std ::endl;
}

void HumanB::attack()
{
    if (this->weapon)
        std ::cout << this->name << " attacks with his " << this->weapon->getType() << std ::endl;
    else
        std ::cout << this->name << " attacks with his bare hands" << std ::endl;
}

void HumanB::setWeapon(Weapon &_weapon)
{        
    this->weapon = &_weapon;
}
