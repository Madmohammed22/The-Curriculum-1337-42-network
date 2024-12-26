#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        Form *form = new ShrubberyCreationForm("home");
        Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 130);
        try
        {
            form->beSigned(*bureaucrat);
            form->execute(*bureaucrat);
            bureaucrat->executeForm(*form);
        }
        catch (const std::exception &e)
        {
            bureaucrat->executeForm(*form);
            std::cerr << e.what() << '\n';
        }
        delete form;
        delete bureaucrat;
    }

    std::cout << "----------------------" << std::endl;
    std::cout << "----------------------" << std::endl;
    {
        Form *form = new RobotomyRequestForm("home");
        Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 20);
        try
        {
            form->beSigned(*bureaucrat);
            form->execute(*bureaucrat);
            bureaucrat->executeForm(*form);
        }
        catch (const std::exception &e)
        {
            bureaucrat->executeForm(*form);
            std::cerr << e.what() << '\n';
        }
        delete form;
        delete bureaucrat;
    }

    std::cout << "----------------------" << std::endl;
    std::cout << "----------------------" << std::endl;
    {
        Form *form = new PresidentialPardonForm("home");
        Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 55);
        try
        {
            form->beSigned(*bureaucrat);
            form->execute(*bureaucrat);
            bureaucrat->executeForm(*form);
        }
        catch (const std::exception &e)
        {
            bureaucrat->executeForm(*form);
            std::cerr << e.what() << '\n';
        }
        delete form;
        delete bureaucrat;
    }
    return 0;
}
