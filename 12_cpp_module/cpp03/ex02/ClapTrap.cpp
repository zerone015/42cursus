#include <iostream>
#include "ClapTrap.hpp"

void    ClapTrap::attack(const std::string &target)
{
    if (!this->ep || !this->hp)
    {
        std::cout << "ClapTrap " << this->name << " can't attack." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
    this->ep--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->name << " hp is reduced by " << amount << std::endl;
    if (this->hp <= amount)
    {
        this->hp = 0;
        std::cout <<  "ClapTrap " << this->name << " is died" << std::endl;
        return ;
    }
    this->hp -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->hp || !this->ep)
    {
        std::cout << "ClapTrap " << this->name << " can't repair." << std::endl;
        return ;
    }
    std::cout << this->name << " hp repaired by " << amount << std::endl;
    this->hp += amount;
    this->ep--;
}

void    ClapTrap::setDamage(unsigned int amount)
{
    std::cout << this->name << " is damage set to " << amount << std::endl;
    this->ad = amount;
}

unsigned int    ClapTrap::getDamage()
{
    return (this->ad);
}

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap " << "Default constructor called" << std::endl;
    this->name = "unknown";
    this->hp = 10;
    this->ep = 10;
    this->ad = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap " << "String constructor called" << std::endl;
    this->name = name;
    this->hp = 10;
    this->ep = 10;
    this->ad = 0;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "ClapTrap " << "Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "ClapTrap " << "Copy assignment operator called" << std::endl;
    this->name = src.name;
    this->hp = src.hp;
    this->ep = src.ep;
    this->ad = src.ad;

    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name <<  " is destroyed" << std::endl;
}