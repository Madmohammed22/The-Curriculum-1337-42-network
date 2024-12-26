#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& a);
    Cat& operator=(const Cat& a);
    ~Cat();
    void makeSound() const;
    std::string getType() const;
    Brain* getBrain() const;

private:
    Brain* brain;
};

#endif