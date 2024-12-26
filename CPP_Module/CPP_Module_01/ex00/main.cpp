#include "Zombie.hpp"

int main(){
    Zombie* obj = newZombie("mohammed");
    obj->announce();
    delete(obj);
    return (0);
}

