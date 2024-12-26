#include "Bureaucrat.hpp"

int main()
{
    {
        try
        {
            Bureaucrat bureaucrat(100, "bureaucrat");
            std::cout << bureaucrat << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            // return -1;
        }
    }

    std::cout << "---------------------------" << std::endl;
    {
        Bureaucrat bureaucrat(1, "bureaucrat");
        try
        {
            bureaucrat.incrementGrade();
            std::cout << bureaucrat << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "---------------------------" << std::endl;

    {
        Bureaucrat bureaucrat(100, "bureaucrat");
        try
        {
            bureaucrat.incrementGrade();
            std::cout << bureaucrat << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}