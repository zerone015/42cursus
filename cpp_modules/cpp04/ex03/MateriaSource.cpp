#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void    MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
    {
		if (source[i] == NULL)
        {
			source[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	int i;
	
	for (i = 0; i < 4; i++)
    {
		if (source[i] && source[i]->getType() == type)
			break ;
	}
	if (i == 4)
		return (NULL);
	return (source[i]->clone());
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    *this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
    {
        delete this->source[i];
        if (src.source[i])
            this->source[i] = src.source[i]->clone();
        else
            this->source[i] = NULL;
    }
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete source[i];
}