
#include "Intern.hpp"

int main()
{
    {
        try
        {    
            Bureaucrat b("Bureaucrat1", 1);
            std::cout << b << std::endl;
        
            Intern intern;
            AForm *form;
            form = intern.makeForm("ShrubberyCreationForm", "Target1");
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "----------------------------------------------"<< std::endl;
    {
        try
        {
            Bureaucrat b("Bureaucrat2", 1);
            std::cout << b << std::endl;
        
            Intern intern;
            AForm *form;
            form = intern.makeForm("UnknownForm", "Target2");
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
    }

}