#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : name("Shrubbery"), checkIfSigned(false), gradeSign(25), gradExecute(5)
{
    std::cout << "[PresidentialPardonForm] Default construct is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string file_target)
    : name(file_target), checkIfSigned(false), gradeSign(25), gradExecute(5), file_target(file_target)
{
    std::cout << "Parameterize constructor is called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s)
    : Form::Form(s), name(s.name), checkIfSigned(s.checkIfSigned), gradeSign(s.gradeSign), gradExecute(s.gradExecute)
{
    std::cout << "[PresidentialPardonForm] Copy constructor is called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this == &other)
        return *this;
    this->checkIfSigned = other.checkIfSigned;
    std::cout << "[PresidentialPardonForm] Assignment operator is called" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "[PresidentialPardonForm] Distructor is called" << std::endl;
}

bool PresidentialPardonForm::FormUp(Bureaucrat &bureaucrat)
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
    {
        bureaucrat.forGradeTwoLow = true;
        GradeTooLowException();
    }
    return false;
}

void PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat)
{
    if (FormUp(bureaucrat) == true)
    {
        bureaucrat.gotSigned = true;
    }
    else
    {
        GradeTooLowException();
    }
    this->checkIfSigned = true;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeSign || executor.getGrade() > this->gradExecute)
    {
        GradeTooLowException();
    }
    std::cout << this->name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getName() const
{
    return this->name;
}

bool PresidentialPardonForm::getCheckIfSigned() const
{
    return this->checkIfSigned;
}
int PresidentialPardonForm::getGradeSign() const
{
    return this->gradeSign;
}

int PresidentialPardonForm::getGradExecute() const
{
    return this->gradExecute;
}
