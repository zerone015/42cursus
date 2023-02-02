#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	Intern	someRandomIntern;
	AForm	*a = NULL;
	AForm	*b = NULL;
	AForm	*c = NULL;
	AForm	*d = NULL;
	
	try
	{
		a = someRandomIntern.makeForm("robotomy request", "Bender");
		b = someRandomIntern.makeForm("presidential pardon", "son");
		c = someRandomIntern.makeForm("shrubbery creation", "kim");
		d = someRandomIntern.makeForm("asdf", "park");
	}
	catch(const std::bad_alloc &e)
	{
		std::cout << "Allocation failed: " << e.what() << std::endl;
	}

	delete a;
	delete b;
	delete c;
	delete d;

	return 0;
}