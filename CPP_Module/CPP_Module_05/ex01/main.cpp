#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        Form form("From", false, 145, 101);
        Bureaucrat bureaucrat("bureaucrat", 101);
        try
        {
            bureaucrat.decrementGrade();
            form.beSigned(bureaucrat);
            bureaucrat.signForm();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            bureaucrat.signForm();
            return 1;
        }
        std::cout << form << std::endl;
    }

    std::cout << "---------------" << std::endl;
    {
        Form form("form", false, 145, 137);
        Bureaucrat bureaucrat("bureaucrat", 100);
        try
        {
            form.beSigned(bureaucrat);
            bureaucrat.signForm();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            bureaucrat.signForm();
            return 1;
        }
        std::cout << form << std::endl;
    }
    return 0;
}