#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm & src);
        ~PresidentialPardonForm();

        std::string getTarget() const;
        
        PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);

        void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & src);

#endif