#include <iostream>
#include "FragTrap.hpp"

void    FragTrap::highFivesGuys(void)
{
    std::cout << "high fives guys" << std::endl;
}

FragTrap::FragTrap()
{
    std::cout << "FragTrap " << "Default constructor called" << std::endl;
    this->name = "unknown";
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap " << "String constructor called" << std::endl;
    this->name = name;
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;
}

FragTrap::FragTrap(const FragTrap &src)
{
    std::cout << "FragTrap " << "Copy constructor called" << std::endl;
    *this = src;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
    std::cout << "FragTrap " << "Copy assignment operator called" << std::endl;
    this->name = src.name;
    this->hp = src.hp;
    this->ep = src.ep;
    this->ad = src.ad;

    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name <<  " is destroyed" << std::endl;
}