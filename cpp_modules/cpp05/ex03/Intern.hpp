#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
    private:
        std::string names[3];
    public:
        Intern();
        Intern(const Intern &src);
        Intern& operator=(const Intern &src);
        ~Intern();
        AForm  *makeForm(std::string name, std::string target);
};

#endif