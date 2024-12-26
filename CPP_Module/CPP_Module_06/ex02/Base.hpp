#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <typeinfo>

class Base {
    public:
        virtual ~Base();

    public:
        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);

};

#endif