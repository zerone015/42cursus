#include <iostream>
#include "ScavTrap.hpp"

void    ScavTrap::attack(const std::string& target)
{
    if (!this->ep || !this->hp)
    {
        std::cout << "ScavTrap " << this->name << " can't attack." << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
    this->ep--;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap " << "Default constructor called" << std::endl;
    this->name = "unknown";
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap " << "String constructor called" << std::endl;
    this->name = name;
    this->hp = 100;
    this->ep = 50;
    this->ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
    std::cout << "ScavTrap " << "Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap " << "Copy assignment operator called" << std::endl;
    this->name = src.name;
    this->hp = src.hp;
    this->ep = src.ep;
    this->ad = src.ad;

    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name <<  " is destroyed" << std::endl;
}