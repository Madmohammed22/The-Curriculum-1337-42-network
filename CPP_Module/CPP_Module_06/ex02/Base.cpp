#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <typeinfo>

Base::~Base()
{
    std::cout << "[Base] Distructor is called" << std::endl;
}

int returnNumber()
{
    int number = 0;
    srand(time(NULL));
    number = rand() % 3 + 1;
    return number;
}
/*
base-to-derived conversions are not allowed
with dynamic_cast unless the base class is polymorphic.
 */

/*
A class that declares or inherits a virtual
function is called a polymorphic class
*/
// class Test : public Base
// {
// };
Base *Base::generate()
{
    int number = returnNumber();
    if (number == 1)
    {
        Base *_Base = dynamic_cast<Base *>(new A);
        // Base *_Base = dynamic_cast<Base *>(new Test);
        return _Base;
    }

    if (number == 2)
    {
        Base *_Base = dynamic_cast<Base *>(new B);
        return _Base;
    }
    if (number == 3)
    {
        Base *_Base = dynamic_cast<Base *>(new C);
        return _Base;
    }
    return NULL;
}

void Base::identify(Base *p)
{
    if (dynamic_cast<A *>(p)){
        dynamic_cast<A *>(p)->function();
    }
    else if (dynamic_cast<B *>(p)){
        dynamic_cast<B *>(p)->function();
    }
    else if (dynamic_cast<C *>(p)){
        dynamic_cast<C *>(p)->function();
    }
    else{
        std::cout << "ERROR" << std::endl;
    }
}

void Base::identify(Base &p)
{

    try
    {
        if (&dynamic_cast<A &>(p))
            dynamic_cast<A &>(p).function();
        else if (&dynamic_cast<B &>(p))
            dynamic_cast<B &>(p).function();
        else if (&dynamic_cast<C &>(p))
            dynamic_cast<C &>(p).function();
    }
    catch (const std::bad_cast &e)
    {
        std::cerr << e.what() << '\n';
    }
}
