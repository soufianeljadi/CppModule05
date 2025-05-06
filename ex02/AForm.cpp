#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm & AForm::operator=(const AForm & rhs)
{
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

std::ostream & operator<<(std::ostream & o, AForm const & i)
{
    o << "Form name: " << i.getName() << ", is " ;
    if(i.getIsSigned())
        o <<  "signed ";
    else
        o << "not signed ";
    o << "| grade to sign: " << i.getGradeToSign() << " | grade to execute: " << i.getGradeToExecute();
    return o;
}


const char * AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade too low";
}

const char * AForm::FormNotSignedException::what() const throw()
{
    return "AForm: Form not signed";
}
