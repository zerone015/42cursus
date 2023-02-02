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
    std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}

HumanB::HumanB()
{
    this->weapon = NULL;
}

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}