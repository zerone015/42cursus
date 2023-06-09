#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat& operator=(const Bureaucrat &src);
        ~Bureaucrat();
        std::string getName() const;
        int         getGrade() const; 
        void        checkGrade(int grade) const;  
        void        increaseGrade();
        void        decreaseGrade(); 
        void        signForm(Form &obj);
        
        class GradeTooHighException : public std::exception 
        {
		    const char  *what() const throw();
	    };
	    class GradeTooLowException : public std::exception 
        {
		    const char  *what() const throw();
	    };
};

std::ostream&   operator<<(std::ostream& outputStream, const Bureaucrat& obj);

#endif