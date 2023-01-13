#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter
{
    private:
        AMateria    *inventory[4];
	    std::string name;
	public:
        Character();
	    Character(std::string name);
	    Character(const Character &src);
	    Character& operator=(const Character &src);
	    ~Character();
        const std::string &getName() const;
	    void        equip(AMateria* m);
	    void        unequip(int idx);
	    void        use(int idx, ICharacter& target);
};

#endif