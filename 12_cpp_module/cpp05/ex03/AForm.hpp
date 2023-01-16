#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           executeGrade;
    public:
        AForm();
        AForm(std::string name, int signGrade, int executeGrade);
        AForm(const AForm &src);
        AForm&          operator=(const AForm &src);
        virtual         ~AForm();
        std::string     getName() const;
        bool            getIsSigned() const;
        int             getSignGrade() const;
        int             getExecuteGrade() const;
        void            beSigned(Bureaucrat &obj);
        void            checkGrade(int grade) const;
        void            checkExecute(int grade) const;
        virtual void    execute(const Bureaucrat &executor) const = 0;

        class GradeTooHighException : public std::exception 
        {
		    const char  *what() const throw();
	    };
	    class GradeTooLowException : public std::exception 
        {
		    const char  *what() const throw();
	    };
        class NotSignedException : public std::exception 
        {
		    const char  *what() const throw();
	    };
        class FileOpenFailedException : public std::exception 
        {
		    const char  *what() const throw();
	    };
};

std::ostream&   operator<<(std::ostream& outputStream, const AForm &obj);

#endif