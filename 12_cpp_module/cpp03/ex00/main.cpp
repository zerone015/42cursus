#include "ClapTrap.hpp"

int main()
{
    ClapTrap    son("son");
    ClapTrap    kim("kim");

    son.setDamage(5);
    son.attack("kim");
    kim.takeDamage(son.getDamage());
    kim.beRepaired(5);
    
    kim.setDamage(10);
    kim.attack("son");
    son.takeDamage(kim.getDamage());
    son.beRepaired(10);
    
    return 0;
}