#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

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
        void        setGrade(int grade);  
        void        increaseGrade();
        void        decreaseGrade(); 
        
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