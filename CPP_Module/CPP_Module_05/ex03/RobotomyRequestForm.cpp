#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : name("Shrubbery"), checkIfSigned(false), gradeSign(72), gradExecute(45)
{
    std::cout << "[RobotomyRequestForm] Default construct is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string file_target)
    : name(file_target), checkIfSigned(false), gradeSign(72),
      gradExecute(45), file_target(file_target)
{
    std::cout << "Parameterize constructor is called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s)
    : Form::Form(s), name(s.name), checkIfSigned(s.checkIfSigned),
      gradeSign(s.gradeSign), gradExecute(s.gradExecute)
{
    std::cout << "[RobotomyRequestForm] Copy constructor is called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other)
        return *this;
    this->checkIfSigned = other.checkIfSigned;
    std::cout << "[RobotomyRequestForm] Assignment operator is called" << std::endl;

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "[RobotomyRequestForm] Distructor is called" << std::endl;
}

void RobotomyRequestForm::trueExeption(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeSign || executor.getGrade() > this->gradExecute)
        GradeTooLowException();
    return;
}
int returnNumber(){
    int number = 0;
    srand (time(NULL));
    number = rand() % 100 + 1;
    return number;
}

bool RobotomyRequestForm::FormUp(Bureaucrat &bureaucrat)
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
    else{
        bureaucrat.forGradeTwoLow = true;
        GradeTooLowException();
    }
    return false;
}

void RobotomyRequestForm::beSigned(Bureaucrat &bureaucrat)
{
    if (FormUp(bureaucrat) == true)
    {
        bureaucrat.gotSigned = true;
    }
    else
        GradeTooLowException();
    this->checkIfSigned = true;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeSign || executor.getGrade() > this->gradExecute)
        GradeTooLowException();
    if (returnNumber() % 2 == 0)
        std::cout << this->name <<" has been robotomized successfully 50 present of the time" << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;

}

std::string RobotomyRequestForm::getName() const
{
    return this->name;
}

bool RobotomyRequestForm::getCheckIfSigned() const
{
    return this->checkIfSigned;
}
int RobotomyRequestForm::getGradeSign() const
{
    return this->gradeSign;
}

int RobotomyRequestForm::getGradExecute() const
{
    return this->gradExecute;
}
