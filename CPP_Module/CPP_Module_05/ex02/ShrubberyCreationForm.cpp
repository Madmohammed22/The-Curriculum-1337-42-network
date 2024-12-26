#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : name("Shrubbery"), checkIfSigned(false), gradeSign(145), gradExecute(137)
{
    std::cout << "[ShrubberyCreationForm] Default construct is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string file_target)
    : name(file_target), checkIfSigned(false), gradeSign(145), gradExecute(137), file_target(file_target)
{
    std::cout << "[ShrubberyCreationForm] Parameterize constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s)
    : Form::Form(s), name(s.name), checkIfSigned(s.checkIfSigned), gradeSign(s.gradeSign), gradExecute(s.gradExecute)
{

    std::cout << "[ShrubberyCreationForm] Copy constructor is called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return *this;
    this->checkIfSigned = other.checkIfSigned;
    std::cout << "[ShrubberyCreationForm] Assignment operator is called" << std::endl;

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "[ShrubberyCreationForm] Distructor is called" << std::endl;
}

bool ShrubberyCreationForm::FormUp(Bureaucrat &bureaucrat)
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

void ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat)
{

    if (FormUp(bureaucrat) == true)
    {
        std::string name = this->name + "_shrubbery";
        std::ofstream file(name.c_str());
        file << "              v .   ._, |_  ., \n"
                "           `-._  .  /    |/_ \n"
                "               ||_ y | / \n"
                "        __.___||, / -.| \n"
                "           7-,--._||  / / , \n"
                "          /'     `-. `./ / |/_. \n"
                "                    |    |// \n"
                "                    |_    / \n"
                "                    |-   | \n"
                "                    |   =| \n"
                "                    |    | \n"
                "--------------------/ ,  . -------\";\n";
        bureaucrat.gotSigned = true;
    }
    else
        GradeTooLowException();
    this->checkIfSigned = true;
}

std::string ShrubberyCreationForm::getName() const
{
    return this->name;
}

bool ShrubberyCreationForm::getCheckIfSigned() const
{
    return this->checkIfSigned;
}
int ShrubberyCreationForm::getGradeSign() const
{
    return this->gradeSign;
}

int ShrubberyCreationForm::getGradExecute() const
{
    return this->gradExecute;
}

void ShrubberyCreationForm::trueExeption(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeSign || executor.getGrade() > this->gradExecute)
        GradeTooLowException();
    return;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeSign || executor.getGrade() > this->gradExecute)
        GradeTooLowException();
    // if (!(this->checkIfSigned == false && executor.getGrade() <= this->gradeSign && executor.getGrade() <= this->gradExecute))
    //     trueExeption(executor);
}
 
