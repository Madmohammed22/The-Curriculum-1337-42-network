#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), gotSigned(false), forGradTwoHight(false), forGradeTwoLow(false)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string bureaucrat, int grade)
    : name(bureaucrat), grade(grade) 
{
    if (this->grade < 1)
        GradeTooHighException();
    else if (this->grade > 150)
        GradeTooLowException(); 
    std::cout << "Parameterize constructor is called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name)
{
    this->grade = b.grade;
    std::cout << "Copy constructor is called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    std::cout << "Assignment operator is called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Distructor is called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::GradeTooHighException()
{
    throw std::runtime_error("[ERROR] Grade Too High");
}

void Bureaucrat::GradeTooLowException()
{
    throw std::runtime_error("[ERROR] Grade Too Low");
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1){
        this->forGradTwoHight = true;
        GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150){
        this->forGradeTwoLow = true;
        GradeTooLowException();
    }
    this->grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << " " << b.getGrade();
    return os;
}

void Bureaucrat::setGrade(int _grade)
{
    this->grade = _grade;
}

void Bureaucrat::signForm()
{
    if (this->gotSigned)
    {
        std::cout << this->name << " signed form" << std::endl;
    }
    else
    {
        std::cout << this->name << " couldn’t sign form because " << writeReason() << std::endl;
    }
}

std::string Bureaucrat::writeReason(){
    if (this->forGradTwoHight == true)
        return "Grade Too High";
    else if (this->forGradeTwoLow == true)
        return "Grade Too Low";
    return "";
}