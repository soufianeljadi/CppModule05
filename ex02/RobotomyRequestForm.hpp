#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

#include <cstdlib>
#include <ctime>


class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        ~RobotomyRequestForm();

        std::string getTarget() const;
        
        RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);

        void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & src);

#endif