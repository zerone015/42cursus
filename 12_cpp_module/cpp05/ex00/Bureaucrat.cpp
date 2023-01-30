#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown"), grade(150) {}
Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) 
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
    const_cast<std::string&>(this->name) = src.name;
    setGrade(src.grade);
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

void    Bureaucrat::setGrade(int grade)
{
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
        this->grade = grade;
    }
    catch (std::exception& e)
    {
        std::cout << "[Exception] " << this->name << ": ";
        std::cout << grade << " ";
        std::cout << e.what() << std::endl;
    }
}

void    Bureaucrat::increaseGrade()
{
    setGrade(this->grade - 1);
}

void    Bureaucrat::decreaseGrade()
{
    setGrade(this->grade + 1);
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