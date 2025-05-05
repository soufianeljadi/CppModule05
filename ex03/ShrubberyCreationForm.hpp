#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        ~ShrubberyCreationForm();

        std::string getTarget() const;
        
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);

        void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & src);

#endif