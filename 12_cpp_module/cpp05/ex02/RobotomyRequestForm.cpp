#include <iostream>
#include <ctime>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src) {}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    AForm           &a = *this;
    const AForm     &b = src;

    a = b;
    return dynamic_cast<RobotomyRequestForm&>(a);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    checkExecute(executor.getGrade());
    std::cout << "(drill sound...)" << std::endl;
	if (rand() % 2)
		std::cout << getName() << " has been successfully robotized." << std::endl;
    else
	    std::cout << getName() << " robotization failed" << std::endl;
}