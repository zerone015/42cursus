#include <iostream>
#include "HumanB.hpp"

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack() const
{
    if (!weapon)
    {
        std::cout << name << " has no weapons" << std::endl;
        return ;
    }
    std::cout << name << " attacks with his " << (*weapon).getType() << std::endl;
}

HumanB::HumanB()
{
    weapon = NULL;
}

HumanB::HumanB(std::string name)
{
    this->name = name;
}