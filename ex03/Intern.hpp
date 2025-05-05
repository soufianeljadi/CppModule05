#ifndef INTERN_HPP
# define INTERN_HPP



#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
    public:
        Intern();
        Intern(const Intern & src);
        ~Intern();
        
        Intern & operator=(const Intern & rhs);

        AForm * makeForm(std::string formName, std::string target);
        
        class FormNotFoundException : public std::exception
        {
            public:
                const char * what() const throw();
        };
};
std::ostream & operator<<(std::ostream & o, Intern const & src);


#endif