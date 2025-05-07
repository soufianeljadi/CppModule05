#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{   
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form & src);
        Form & operator=(const Form & rhs);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat & bureaucrat);
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw();

        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw();
        };

        class AlreadySigned : public std::exception
        {
            public:
                const char * what() const throw();
        };

};


std::ostream & operator<<(std::ostream & o, Form const & src);
#endif