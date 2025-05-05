#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const & src);
        Bureaucrat & operator=(Bureaucrat const & src);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        void signForm(AForm & aform);
        void executeForm(AForm const & aform) const;

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);
#endif