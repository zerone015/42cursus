#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    AForm           &a = *this;
    const AForm     &b = src;

    a = b;
    return dynamic_cast<ShrubberyCreationForm&>(a);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string getAsciiTrees()
{
    return  "       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n    ###\\|/#o#\n     # }|{  #\n       }|{";
}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    std::ofstream fout;

    checkExecute(executor.getGrade());
    fout.open((getName() + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (fout.is_open() == false)
        throw FileOpenFailedException();
    fout << getAsciiTrees();
    fout.close();
}