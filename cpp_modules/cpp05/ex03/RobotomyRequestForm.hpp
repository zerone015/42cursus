#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm&  operator=(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        virtual void execute(const Bureaucrat &executor) const;
};

#endif