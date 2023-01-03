#include <iostream>
#include "Zombie.hpp"

void    Zombie::setName(std::string name)
{
    this->name = name;
}

void    Zombie::announce(void) const
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << name << " is destroyed" << std::endl;
}