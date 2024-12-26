#include "Zombie.hpp"

int main()
{
    long n = 5;
    if (n < 0)
        return 1;
    std :: string name = "mohammed";
    Zombie* obj = zombieHorde(n, name);
    if (obj == NULL){
        delete [] obj;    
        return 1;
    }
        
    for (int i = 0; i < n; i++)
    {
        obj->announce();
    }
    delete [] obj;
    return (0);
}