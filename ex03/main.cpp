
#include "Intern.hpp"

int main()
{

    Bureaucrat b("Bureaucrat1", 1);
    std::cout << b << std::endl;

    Intern intern;
    AForm *form;

    try
    {
        form = intern.makeForm("PresidentialPardonForm", "Target1");
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
        form = intern.makeForm("RobotomyRequestForm", "Target2");
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
        form = intern.makeForm("ShrubberyCreationForm", "Target3");
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

}