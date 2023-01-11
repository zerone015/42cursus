#include "ScavTrap.hpp"

int main()
{
    ScavTrap    son("son");
    ScavTrap    kim("kim");

    son.attack("kim");
    kim.takeDamage(son.getDamage());
    kim.beRepaired(20);

    for (int i = 0; i < 5; i++)
    {
        kim.attack("son");
        son.takeDamage(kim.getDamage());
    }
    son.beRepaired(10);
    kim.guardGate();
    return 0;
}