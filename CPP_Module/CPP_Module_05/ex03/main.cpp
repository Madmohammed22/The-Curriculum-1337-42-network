#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <typeinfo>

class Base
{
    int baseData;

public:
    Base()
    {
        this->baseData = 11;
    }

public:
    virtual void Do()
    {
        std::cout << "baseData " << baseData << std::endl;
    }
};

class Derive : public Base
{
    int deriveData;

public:
    Derive()
    {
        this->deriveData = 22;
    }

public:
    void Do()
    {
        std::cout << "deriveData " << deriveData << std::endl;
    }
};

class ExternalClass
{
    int ExternalData;

public:
    ExternalClass()
    {
        this->ExternalData = 22;
    }

public:
    void Do()
    {
        std::cout << "ExternalData " << ExternalData << std::endl;
    }
};

// int main__()
// {
//     // {
//     //     Intern someRandomIntern;
//     //     Form *rrf;
//     //     rrf = someRandomIntern.makeForm("robotomy request", "Bender");
//     //     if (rrf)
//     //         std:: cout << rrf->getName() << std::endl;
//     // }
//     {
//         Base base;
//         Derive derive;
//         base.Do();
//         derive.Do();
//         (static_cast<Base>(derive)).Do();
//         // (static_cast<Derive>(base)).Do();
//     }
//     std::cout << "-------------------------" << std::endl;
//     std::cout << "-------------------------" << std::endl;
//     {
//         int *number = new int(20);
//         float result = dynamic_cast<float *>(number);
//         std::cout << result << std::endl;
//         Base *base = new Base;
//         Derive *derive = new Derive;
//         ExternalClass *exeternal = new ExternalClass;
//         base->Do();
//         derive->Do();
//         if (dynamic_cast<ExternalClass *>(derive))
//         {
//             std::cout << "I was here" << std::endl;
//             (dynamic_cast<ExternalClass *>(derive))->Do();
//         }
//         // derive->Do();
//     }

//     return 0;
// }

// #include <iostream>
// #include <typeinfo>

// struct Foo { virtual ~Foo() {} };
// struct Bar { virtual ~Bar() { std::cout << "~Bar\n"; } };
// struct Pub : Bar { ~Pub() override { std::cout << "~Pub\n"; } };

// int main()
// {
//     Pub *pub = new Pub;
//     try
//     {
//         // [[maybe_unused]]
//         // Bar& r1 = dynamic_cast<Bar&>(pub); // OK, upcast
//         // [[maybe_unused]]
//         if (!dynamic_cast<Foo*>(pub))
//             std::cout << "ERROR" << std::endl;
//         Foo* r2 = dynamic_cast<Foo*>(pub); // throws
//     }
//     catch (const std::bad_cast& e)
//     {
//         std::cout << "e.what(): " << e.what() << '\n';
//     }
// }

int main()
{
    {
        Intern someRandomIntern;
        Form *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
            std::cout << rrf->getName() << std::endl;
    }
}