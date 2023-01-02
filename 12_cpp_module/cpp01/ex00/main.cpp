#include "Zombie.hpp"

int main(void)
{
    Zombie  stack_zombie("stack");
    Zombie  *heap_zombie = newZombie("heap");

    stack_zombie.announce();
    heap_zombie->announce();

    randomChump("chump");

    delete heap_zombie;
    return (0);
}