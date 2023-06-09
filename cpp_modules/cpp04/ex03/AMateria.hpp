#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(const std::string &type);
        AMateria(const AMateria &src);
        AMateria&           operator=(const AMateria &src);
        virtual ~AMateria();
        const std::string   &getType() const;
        virtual AMateria    *clone() const = 0;
        virtual void        use(ICharacter& target);
};

#endif