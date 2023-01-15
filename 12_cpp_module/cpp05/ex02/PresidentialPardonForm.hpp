#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm&  operator=(const PresidentialPardonForm &src);
        ~PresidentialPardonForm();
        virtual void execute(const Bureaucrat &executor) const;
};

#endif