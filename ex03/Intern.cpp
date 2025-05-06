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

AForm * Intern::makeForm(std::string formName, std::string target)
{
    AForm *form = NULL;
    std ::string arr[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    int i = 0;

    while (i < 3)
    {
        if (formName == arr[i])
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            form = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            break;
        case 1:
            form = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            break;
        case 2:
            form = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            break;
        default:
            throw FormNotFoundException();
    }
    return form;
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
