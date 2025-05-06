#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default")
{
    this->_grade = 150;
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name)
{
    *this = src;
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    this->_grade = src._grade;
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade();
    return o;
}

void Bureaucrat::signForm(AForm &aform) 
{
    try
    {
        aform.beSigned(*this);
        std::cout << this->_name << " signed " << aform.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << this->_name << " couldn't sign " << aform.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & aform) const
{
    try
    {
        aform.execute(*this);
        std::cout << this->_name << " executed " << aform.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << this->_name << " couldn't execute " << aform.getName() << " because " << e.what() << std::endl;
    }
}