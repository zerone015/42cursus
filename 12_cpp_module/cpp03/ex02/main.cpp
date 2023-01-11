#include "FragTrap.hpp"

int main()
{
    FragTrap    son("son");
    FragTrap    kim("kim");

    son.attack("kim");
    kim.takeDamage(son.getDamage());
    kim.beRepaired(30);

    for (int i = 0; i < 4; i++)
    {
        kim.attack("son");
        son.takeDamage(kim.getDamage());
    }
    son.beRepaired(10);
    kim.highFivesGuys();
    return 0;
}