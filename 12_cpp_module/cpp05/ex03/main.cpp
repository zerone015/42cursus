#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	Intern	someRandomIntern;

	AForm	*a = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm	*b = someRandomIntern.makeForm("presidential pardon", "son");
	AForm	*c = someRandomIntern.makeForm("shrubbery creation", "kim");
	AForm	*d = someRandomIntern.makeForm("not exists", "park");

	delete a;
	delete b;
	delete c;
	delete d;

	return 0;
}