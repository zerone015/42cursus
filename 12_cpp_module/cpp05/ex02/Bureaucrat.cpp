#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown"), grade(150) {}
Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) 
{
    try
    {
        checkGrade(grade);
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << ": " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
    const_cast<std::string&>(this->name) = src.name;
    this->grade = src.grade;
    try
    {
        checkGrade(this->grade);
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << ": " << e.what() << std::endl;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void    Bureaucrat::checkGrade(int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void    Bureaucrat::increaseGrade()
{
    try
    {
        checkGrade(this->grade - 1);
        this->grade--;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << ": " << "can't increase grade because " << e.what() << std::endl;
    }
}

void    Bureaucrat::decreaseGrade()
{
    try
    {
        checkGrade(this->grade + 1);
        this->grade++;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << ": " << "can't decrease grade because " << e.what() << std::endl;
    }
}

void    Bureaucrat::signForm(AForm &obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << this->name << " signed " << obj.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn’t sign " << obj.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " failed to execute form " << form.getName() << " because " << e.what() << std::endl;
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low.");
}

std::ostream&   operator<<(std::ostream& outputStream, const Bureaucrat& obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return outputStream;
}