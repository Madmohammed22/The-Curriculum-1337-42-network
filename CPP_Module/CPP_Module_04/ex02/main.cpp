#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"


int main__()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    j->makeSound(); // atack lih
    i->makeSound(); // pretty cute cate no body talk to you
    delete j; // should not create a leak
    delete i;
    return 0;
}

int main()
{
    main__();
    // system("leaks main");
    return 0;
}