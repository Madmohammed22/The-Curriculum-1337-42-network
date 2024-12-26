#include "Weapon.hpp"

Weapon::Weapon(std::string _type) {
    this->type = _type;
}

Weapon::~Weapon() {
    std :: cout << "Weapon destroyed" << std :: endl;
}

const std::string& Weapon::getType(){
    return this->type;
}

void Weapon::setType(const std::string& type){
    this->type = type;
}
