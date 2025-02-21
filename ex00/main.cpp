
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b("Ben10", 1);
    std::cout << b.getName() << " has Grade : " << b.getGrade() << std::endl;

    try
    {
        b.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << b.getName() << " has Grade : " << b.getGrade() << std::endl;
    b.decrementGrade();
    std::cout << b.getName() << " has Grade : " << b.getGrade() << std::endl;
    return 0;
}