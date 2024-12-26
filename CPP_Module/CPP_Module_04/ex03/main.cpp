#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

// int main__()
// {
//     MateriaSource source;
//     source.learnMateria(new Ice());
//     source.learnMateria(new Cure());

//     Character alice("Alice");
//     AMateria *ice = source.createMateria("ice");
//     AMateria *cure = source.createMateria("cure");

//     alice.equip(ice);
//     alice.equip(cure);

//     Character bob("Bob");
//     alice.use(0, bob); // Alice uses ice on Bob
//     alice.use(1, bob); // Alice uses cure on Bob

//     return 0;
// }

int main__()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}

int main()
{
    main__();
    // system("leaks main");
    return 0;
}