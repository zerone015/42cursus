#include "AMateria.hpp"

const std::string   &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	target.getName();
}

AMateria::AMateria(){}

AMateria::AMateria(const std::string &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	this->type = src.type;

	return (*this);
}

AMateria::~AMateria(){}