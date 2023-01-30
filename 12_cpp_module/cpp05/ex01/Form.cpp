#include <iostream>
#include <cstdlib>
#include "Form.hpp"

Form::Form() : name("unknown"), isSigned(false), signGrade(150), executeGrade(150) {}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    try
    {
        checkGrade(this->signGrade);
        checkGrade(this->executeGrade);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n"
                  << "exit program" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

Form::Form(const Form &src) : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), executeGrade(src.executeGrade)
{
    try
    {
        checkGrade(this->signGrade);
        checkGrade(this->executeGrade);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n"
                  << "exit program" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

Form&   Form::operator=(const Form &src)
{
    try
    {
        checkGrade(src.signGrade);
        checkGrade(src.executeGrade);
        const_cast<int&>(this->signGrade) = src.signGrade;
        const_cast<int&>(this->executeGrade) = src.executeGrade;
        const_cast<std::string&>(this->name) = src.name;
        this->isSigned = src.isSigned;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n"
                  << "exit program" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
    return this->name;
}

bool    Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getSignGrade() const
{
    return this->signGrade;
}

int Form::getExecuteGrade() const
{
    return this->executeGrade;
}

void    Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}

void    Form::checkGrade(int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low.";
}

std::ostream&   operator<<(std::ostream& outputStream, const Form &obj)
{
    std::cout << "[ Form informations ]" << "\n";
    std::cout << "Name: " << obj.getName() << "\n";
    std::cout << "signed: " << std::boolalpha << obj.getIsSigned() << "\n";
    std::cout << "sign grade: " << obj.getSignGrade() << "\n";
    std::cout << "execute grade: " << obj.getExecuteGrade() << std::endl;

	return outputStream;
}