#include "ClapTrap.hpp"

int main()
{
    ClapTrap    son("son");
    ClapTrap    kim("kim");

    son.attack("kim");
    kim.takeDamage(5);
    kim.beRepaired(5);
    
    kim.attack("son");
    son.takeDamage(10);
    son.beRepaired(10);
    
    return 0;
}