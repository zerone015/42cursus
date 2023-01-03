#include <iostream>
#include "HumanA.hpp"

void    HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){}