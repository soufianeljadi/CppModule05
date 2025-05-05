#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    Form form("Form1", 50, 50);
    Bureaucrat b("Bureaucrat1", 50);
    std::cout << b << std::endl;
    std::cout << form << std::endl;
    try
    {
        b.signForm(form);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << form << std::endl;

}