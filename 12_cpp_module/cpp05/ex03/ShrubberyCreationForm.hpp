#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();
        virtual void execute(const Bureaucrat &executor) const;
};

#endif