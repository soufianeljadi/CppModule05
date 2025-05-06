#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern & src)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}


Intern & Intern::operator=(const Intern & rhs)
{
    (void)rhs;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

static AForm	*PresidentialForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*RobotomyForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*ShrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm * Intern::makeForm(std::string formName, std::string target)
{

    AForm *(*forms_pointer[])(const std::string target) = {&PresidentialForm, &RobotomyForm, &ShrubberyForm};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms_pointer[i](target);
        }
    }
    throw FormNotFoundException();
    return NULL;
}

const char * Intern::FormNotFoundException::what() const throw()
{
    return "Intern: Form not found";
}

std::ostream & operator<<(std::ostream & o, Intern const & src)
{
    (void)src;
    o << "Intern object";
    return o;
}
