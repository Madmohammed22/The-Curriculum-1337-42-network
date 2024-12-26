#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon) : name(_name), weapon(_weapon)
{
    this->name = _name;
    this->weapon = _weapon;
}

HumanA::~HumanA()
{
    std ::cout << "HumanA destroyed" << std ::endl;
}

void HumanA::attack()
{
    std ::cout << this->name << " attacks with his " << this->weapon.getType() << std ::endl;
}

