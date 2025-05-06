#include "Form.hpp"

int main()
{
    try
    {
        Form form("Form1", 50, 50);
        Bureaucrat b("B1", 50);
        std::cout << b << std::endl;
        std::cout << form << std::endl;
        b.signForm(form);
        std::cout << form << std::endl;            
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;

    }
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        Form form("Form2", 3, 5);
        Bureaucrat b("B2", 10);
        std::cout << b << std::endl;
        std::cout << form << std::endl;
        b.signForm(form);
        std::cout << form << std::endl;            
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

}