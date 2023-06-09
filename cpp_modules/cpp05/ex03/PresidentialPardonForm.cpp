#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src) {}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    AForm           &a = *this;
    const AForm     &b = src;

    a = b;
    return dynamic_cast<PresidentialPardonForm&>(a);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    checkExecute(executor.getGrade());
    std::cout << getName() << " was pardoned by Jaford Biblbrox." << std::endl;
}