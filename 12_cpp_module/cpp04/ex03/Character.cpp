#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character()
{
    this->name = "unknown";
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character &src)
{
    *this = src;
}

Character& Character::operator=(const Character &src)
{
    this->name = src.name;
    for (int i = 0; i < 4; i++)
    {
        delete this->inventory[i];
        if (src.inventory[i])
            this->inventory[i] = src.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete this->inventory[i];
}

const std::string&   Character::getName() const
{
    return this->name;
}

void    Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            break ;
        }
    }
}

void    Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
        this->inventory[idx] = NULL;
}

void    Character::use(int idx, ICharacter &target)
{
    if (0 <= idx && idx <= 3 && this->inventory[idx])
		this->inventory[idx]->use(target);
}