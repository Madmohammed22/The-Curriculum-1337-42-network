#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

using namespace std;
class Weapon
{
private:
    std::string type;
public:
    Weapon(std :: string _type) ;
    ~Weapon();
    const std::string& getType();
    void setType(const std::string& type);
};

#endif