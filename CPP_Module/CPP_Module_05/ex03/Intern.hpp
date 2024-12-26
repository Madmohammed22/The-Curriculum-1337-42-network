#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
class Intern{

public:
    Intern();
    Intern(const Intern& i);
    Intern& operator=(const Intern& other);
    ~Intern();

public: Form* makeForm(std::string name_form, std::string target_form);
    
};



#endif

