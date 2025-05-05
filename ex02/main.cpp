#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
    Bureaucrat b("Bureaucrat1", 1);
    std::cout << b << std::endl;

    RobotomyRequestForm r("RobotomyRequestForm");
    PresidentialPardonForm p("PresidentialPardonForm");
    ShrubberyCreationForm s("ShrubberyCreationForm");

    std::cout << r << std::endl;
    std::cout << p << std::endl;
    std::cout << s << std::endl;

    try
    {
        b.signForm(r);
        b.signForm(p);
        b.signForm(s);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << r << std::endl;
    std::cout << p << std::endl;
    std::cout << s << std::endl;

    try
    {
        b.executeForm(r);
        b.executeForm(p);
        b.executeForm(s);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }


}