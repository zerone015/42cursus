#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    this->names[0] = "presidential pardon";
    this->names[1] = "robotomy request";
    this->names[2] = "shrubbery creation";
}

Intern::Intern(const Intern &src) 
{
    this->names[0] = src.names[0];
    this->names[1] = src.names[1];
    this->names[2] = src.names[2];
}

Intern& Intern::operator=(const Intern &src) 
{
    this->names[0] = src.names[0];
    this->names[1] = src.names[1];
    this->names[2] = src.names[2];
    
    return *this;
}

Intern::~Intern() {}

AForm*  Intern::makeForm(std::string name, std::string target)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (this->names[i] == name)
            break ;
    }
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << name << std::endl;
            return new PresidentialPardonForm(target);
        case 1:
            std::cout << "Intern creates " << name << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << name << std::endl;
            return new ShrubberyCreationForm(target);
        default:
            std::cout << "The name " << name << " doesn’t exist." << std::endl;
    }
    return NULL;
}