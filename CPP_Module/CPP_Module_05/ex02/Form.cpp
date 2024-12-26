#include "Form.hpp"

Form::Form() : name("Form"), checkIfSigned(false), gradeSign(1), gradExecute(150)
{
    std::cout << GREEN << "[Form] Default constructor is called" << RESET << std::endl;
}

Form::Form(std::string name, bool checkIfSigned, int gradeSign, int gradExecute)
    : name(name), checkIfSigned(checkIfSigned), gradeSign(gradeSign), gradExecute(gradExecute)
{
    std::cout << GREEN << "[Form] Parameterize constructor is called." << RESET << std::endl;
}

Form::Form(const Form &f) : name(f.name), gradeSign(f.gradeSign), gradExecute(f.gradExecute)
{
    std::cout << GREEN << "[Form] Copy constructor is called" << RESET << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this == &other)
        return *this;
    std::cout << GREEN << "Assignment operator is called" << RESET << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << GREEN << "Distructor is called" << RESET << std::endl;
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getCheckIfSigned() const
{
    return this->checkIfSigned;
}
int Form::getGradeSign() const
{
    return this->gradeSign;
}

int Form::getGradExecute() const
{
    return this->gradExecute;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName() << " " << f.getCheckIfSigned()
       << " " << f.getGradeSign()
       << " " << f.getGradExecute();
    return os;
}

void Form::GradeTooHighException()
{
    throw std::runtime_error("[Error] Grade Too High");
}

void Form::GradeTooLowException()
{
    throw std::runtime_error("[Error] Grade Too Low");
}

bool Form::FormUp(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() < 1)
    {
        bureaucrat.forGradTwoHight = true;
        GradeTooHighException();
    }
    else if (bureaucrat.getGrade() > 150)
    {
        bureaucrat.forGradeTwoLow = true;
        GradeTooLowException();
    }

    if ((bureaucrat.getGrade() <= this->gradeSign) && bureaucrat.getGrade() <= this->gradExecute)
    {
        return true;
    }
    else
        bureaucrat.forGradeTwoLow = true;
    return false;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (FormUp(bureaucrat) == true){
        bureaucrat.gotSigned = true;
        this->checkIfSigned = true;
    }
    return;
}
