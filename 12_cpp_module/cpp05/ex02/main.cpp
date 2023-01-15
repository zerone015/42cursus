#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	Bureaucrat a("a", 5);
	Bureaucrat b("b", 50);
	Bureaucrat c("c", 150);

	ShrubberyCreationForm sc("SC");
	RobotomyRequestForm rr("RR");
	PresidentialPardonForm pp("PP");

	std::cout << sc << std::endl;
	std::cout << rr << std::endl;
	std::cout << pp << std::endl << std::endl;
	
	c.signForm(sc);
	c.signForm(rr);
	c.signForm(pp);

	std::cout << sc << std::endl;
	std::cout << rr << std::endl;
	std::cout << pp << std::endl <<std::endl;

	a.signForm(sc);
	b.signForm(rr);
	b.signForm(pp);

	a.executeForm(sc);
	b.executeForm(rr);
	c.executeForm(pp);
	a.executeForm(pp);

	for (int i = 0; i < 10; i++)
		a.executeForm(rr);
	a.signForm(pp);
	a.executeForm(pp);

	ShrubberyCreationForm test1(sc);
	std::cout << "\n" << test1 << std::endl;
	
	ShrubberyCreationForm test2("Hi");
	test2 = sc;
	std::cout << "\n" << test2 << std::endl;
	
	return 0;
}