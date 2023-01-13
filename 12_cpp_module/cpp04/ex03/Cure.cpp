#include <iostream>
#include "Cure.hpp"

Cure* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &src)
{
	*this = src;
}

Cure& Cure::operator=(const Cure &src)
{
	this->type = src.type;

	return *this;
}

Cure::~Cure(){}