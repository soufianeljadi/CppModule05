#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src), _target(src._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    srand(time(NULL));
    if (rand() % 2 == 0)
    {
        std::cout << "Bzzzzzz... Bzzzzzz... Bzzzzzz..." << std::endl;
        std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;   
    }
	else
		std::cout << "Robotomy failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}


std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & src)
{
    o << "RobotomyRequestForm: " << src.getName() << ", target: " << src.getTarget();
    if(src.getIsSigned())
        o <<  " signed ";
    else
        o << " not signed ";
    o << "| grade to sign: " << src.getGradeToSign() << " | grade to execute: " << src.getGradeToExecute();
    return o;
}

