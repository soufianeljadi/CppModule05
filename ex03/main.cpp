#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main()
{

    Bureaucrat b("Bureaucrat1", 1);
    std::cout << b << std::endl;

    Intern intern;
    AForm *form;

    try
    {
        form = intern.makeForm("robotomy request", "Target1");
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        form = intern.makeForm("presidential pardon", "Target2");
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        form = intern.makeForm("shrubbery creation", "Target3");
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

}