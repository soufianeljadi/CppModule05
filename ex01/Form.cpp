#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

Form & Form::operator=(const Form & rhs)
{
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

std::ostream & operator<<(std::ostream & o, Form const & i)
{
    o << "Form name: " << i.getName() << ", is " ;
    if(i.getIsSigned())
        o <<  "signed ";
    else
        o << "not signed ";
    o << "| grade to sign: " << i.getGradeToSign() << " | grade to execute: " << i.getGradeToExecute();
    return o;
}


const char * Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low";
}

