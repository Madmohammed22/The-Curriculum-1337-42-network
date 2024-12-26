#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{

public:
    Form();
    Form(std::string name, bool checkIfSigned, int gradeSign, int gradExecute);
    Form(const Form &f);
    Form &operator=(const Form &other);
    virtual ~Form() = 0;

private:
    const std::string name;
    bool checkIfSigned;
    const int gradeSign;
    const int gradExecute;

public:
    virtual std::string getName() const;
    virtual bool getCheckIfSigned() const;
    virtual int getGradeSign() const;
    virtual int getGradExecute() const;

public:

    void GradeTooHighException();
    static void GradeTooLowException();
    virtual void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;
    
public : virtual bool FormUp(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif