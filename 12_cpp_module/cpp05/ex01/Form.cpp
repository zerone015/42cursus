#include <iostream>
#include "Form.hpp"

Form::Form() : name("unknown"), isSigned(false), signGrade(150), executeGrade(150) {}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) 
{
    try
    {
        if (this->signGrade < 1 || this->executeGrade < 1)
            throw GradeTooHighException();
        if (this->signGrade > 150 || this->executeGrade > 150)
            throw GradeTooLowException();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

Form::Form(const Form &src) : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), executeGrade(src.executeGrade)
{
    try
    {
        if (this->signGrade < 1 || this->executeGrade < 1)
            throw GradeTooHighException();
        if (this->signGrade > 150 || this->executeGrade > 150)
            throw GradeTooLowException();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

Form&   Form::operator=(const Form &src)
{
    try
    {
        if (src.signGrade < 1 || src.executeGrade < 1)
            throw GradeTooHighException();
        if (src.signGrade > 150 || src.executeGrade > 150)
            throw GradeTooLowException();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    const_cast<int&>(this->signGrade) = src.signGrade;
    const_cast<int&>(this->executeGrade) = src.executeGrade;
    const_cast<std::string&>(this->name) = src.name;
    this->isSigned = src.isSigned;
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
    try
    {
        if (obj.getGrade() > this->signGrade)
            throw GradeTooLowException();
        this->isSigned = true;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
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
    std::cout << "signed: " << obj.getIsSigned() << "\n";
    std::cout << "sign grade: " << obj.getIsSigned() << "\n";
    std::cout << "execute grade: " << obj.getExecuteGrade() << std::endl;

	return outputStream;
}