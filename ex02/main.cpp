
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
    try
    {    
        Bureaucrat b("Bureaucrat1", 1);
        std::cout << b << std::endl;
    
        ShrubberyCreationForm s("ShrubberyCreationForm");
    
        std::cout << s << std::endl;
        b.signForm(s);
        b.executeForm(s);
        std::cout << s << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

}