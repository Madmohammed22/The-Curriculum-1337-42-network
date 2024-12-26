#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "[Intern] Default construct is called" << std::endl;
}

Intern::Intern(const Intern &i)
{
    (void)i;
    std::cout << "[Intern] Copy constructor is called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "[Intern] Assignment operator is called" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "[Intern] Distructor is called" << std::endl;
}

int hashit(std::string name_form)
{
    std::string arr[4] = {"shrubbery creation", "robotomy request", "presidential pardon", ""};
    int i = 0;
    while (name_form != arr[i] && !arr[i].empty())
        i++;
    return i + 1;
}

Form *executeClassTarget(std::string name_form, std::string target_form)
{
    Form *result = NULL;

    switch (hashit(name_form))
    {
    case 1:
        result = new ShrubberyCreationForm(target_form);
        break;
    case 2:
        result = new RobotomyRequestForm(target_form);
        break;
    case 3:
        result = new PresidentialPardonForm(target_form);
        break;
    case 4:
        std::cout << "Invalid form_name" << std::endl;
        return NULL;
    }
    return result;
}

Form *Intern::makeForm(std::string name_form, std::string target_form)
{
    Form *form = executeClassTarget(name_form, target_form);
    if (form)
        std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}