#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           executeGrade;
    public:
        Form();
        Form(std::string name, int signGrade, int executeGrade);
        Form(const Form &src);
        Form&       operator=(const Form &src);
        ~Form();
        std::string getName() const;
        bool        getIsSigned() const;
        int         getSignGrade() const;
        int         getExecuteGrade() const;
        void        beSigned(Bureaucrat &obj);

        class GradeTooHighException : public std::exception 
        {
		    const char  *what() const throw();
	    };
	    class GradeTooLowException : public std::exception 
        {
		    const char  *what() const throw();
	    };
};

std::ostream&   operator<<(std::ostream& outputStream, const Form &obj);

#endif