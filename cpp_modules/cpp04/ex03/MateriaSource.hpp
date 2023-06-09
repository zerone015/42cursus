#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *source[4];
    public:
        MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource& operator=(const MateriaSource &src);
        ~MateriaSource();
        void        learnMateria(AMateria *);
        AMateria    *createMateria(const std::string &type);
};

#endif