#include "Zombie.hpp"

Zombie *newZombieN(std::string name, int n)
{
    Zombie *horde = new(std::nothrow)Zombie[n];
    if (horde == NULL)
        return NULL;
    for (int i = 0; i < n; i++)
    {
        horde[i].setName(name);
    }
    return horde;
}
Zombie *zombieHorde(int N, std::string name)
{
    Zombie *obj = newZombieN(name, N);
    if (obj == NULL)
        return NULL;
    return (obj);
}
