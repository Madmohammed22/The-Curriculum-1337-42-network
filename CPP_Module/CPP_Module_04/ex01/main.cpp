#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main_()
{
    // const int size = 6;
    // const Animal* animal[size];
    // for (int i = 0; i < size / 2; i++){
    //     animal[i] = new Cat();
    // }

    // for (int i = size / 2; i < size; i++){
    //     animal[i] = new Dog();
    // }

    // for (int i = 0; i < size; i++){
    //     animal[i]->makeSound();
    // }
    const Animal *animal1 = new Cat();
    // animal1->makeSound();
    const Animal *animal2 = new Dog();
    animal2 = animal1;
    animal2->makeSound();
    // for (int i = 0; i < size ; i++){
    //     delete animal[i];
    // }
    return EXIT_SUCCESS;
}

int main___()
{
    main_();
    // system("leaks main");
    return EXIT_SUCCESS;
}

class Shallow
{
public:
    int *data;

public:
    Shallow(int value) : data(new int(value))
    {
    }

public:
    Shallow(const Shallow &other) : data(other.data)
    { // copies the pointer
        std ::cout << "Shallow copu made!" << std ::endl;
    }
    ~Shallow()
    {
        delete data; // both object may try to delete the
                     // same memory
        std ::cout << "Destructor called" << std ::endl;
    }
};

class Deep
{
public:
    int *data;

public:
    Deep(int value) : data(new int(value))
    {
    }

public:
    Deep(const Deep &other) : data(new int(*other.data))
    { // copies the value
        std ::cout << "Deep copu made!" << std ::endl;
    }
    ~Deep()
    {
        delete data; // safely deletes its own memory
        std ::cout << "Destructor called" << std ::endl;
    }
};

int main__()
{
    Deep obj1(42);
    Deep obj2 = obj1; // Deep copy
    *obj2.data = 100;
    std::cout << "obj1 data: " << *obj1.data << std::endl; // Outputs 100
    // Destructor called : double free or corruption error likely here.
    return EXIT_SUCCESS;
}

int main_2()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    // Test for deep copy
    Cat originalCat;
    Cat copiedCat(originalCat);

    // Modify the original cat's brain to see if it affects the copied cat's brain
    originalCat.getBrain()->setIdea(0, "Original Cat's Idea");
    copiedCat.getBrain()->setIdea(0, "Copied Cat's Idea");

    std::cout << "Original Cat's Brain Idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat's Brain Idea: " << copiedCat.getBrain()->getIdea(0) << std::endl;

    return 0;
}

int main_____()
{
    main_2();
    system("leaks main");
    return EXIT_SUCCESS;
}

int main_22()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    j->makeSound();
    i->makeSound();    
    delete j; // should not create a leak
    delete i;
    return 0;
}

int main()
{
    main_22();
    // system("leaks main");
    return EXIT_SUCCESS;
}

