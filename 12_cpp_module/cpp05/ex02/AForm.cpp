#include <iostream>
#include "AForm.hpp"

AForm::AForm() : name("unknown"), isSigned(false), signGrade(150), executeGrade(150) {}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) 
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

AForm::AForm(const AForm &src) : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), executeGrade(src.executeGrade)
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

AForm&   AForm::operator=(const AForm &src)
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

AForm::~AForm() {}

std::string AForm::getName() const
{
    return this->name;
}

bool    AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->executeGrade;
}

void    AForm::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}

void    AForm::checkGrade(int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void    AForm::checkExecute(int grade) const
{
    if (this->isSigned == false)
        throw NotSignedException();
    if (this->executeGrade < grade)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low.";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "This form has not been signed.";
}

const char* AForm::FileOpenFailedException::what() const throw()
{
	return "Failed to open file.";
}

std::ostream&   operator<<(std::ostream& outputStream, const AForm &obj)
{
    std::cout << "[ AForm informations ]" << "\n";
    std::cout << "Name: " << obj.getName() << "\n";
    std::cout << "signed: " << std::boolalpha << obj.getIsSigned() << "\n";
    std::cout << "sign grade: " << obj.getSignGrade() << "\n";
    std::cout << "execute grade: " << obj.getExecuteGrade() << std::endl;

	return outputStream;
}