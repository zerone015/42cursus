#include <iostream>
#include "Ice.hpp"

Ice* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &src)
{
	*this = src;
}

Ice& Ice::operator=(const Ice &src)
{
	this->type = src.type;

	return *this;
}

Ice::~Ice(){}