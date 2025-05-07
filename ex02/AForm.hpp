#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{   
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm & src);
        virtual ~AForm();
        
        AForm & operator=(const AForm & rhs);

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat & bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

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
        class FormNotSignedException : public std::exception
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


std::ostream & operator<<(std::ostream & o, AForm const & src);
#endif