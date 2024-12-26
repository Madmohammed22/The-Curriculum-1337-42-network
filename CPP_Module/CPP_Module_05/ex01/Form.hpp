#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{

public:
    Form();
    Form(std::string name, bool checkIfSigned
        , int gradeSign, int gradExecute);
    Form(const Form &f);
    Form &operator=(const Form &other);
    ~Form();

private:
    const std::string name;
    bool checkIfSigned;
    const int gradeSign;
    const int gradExecute;

public:
    std::string getName() const;
    bool getCheckIfSigned() const;
    int getGradeSign() const;
    int getGradExecute() const;

public:
    void GradeTooHighException();
    void GradeTooLowException();
    void beSigned(Bureaucrat &bureaucrat);

public : bool FormUp(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &f);
#endif