#include <iostream>
#include "DiamondTrap.hpp"

void    DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name is " << name << " and ClapTrap name is " << ClapTrap::name << std::endl;
}

void    DiamondTrap::showStatus(void)
{
    std::cout << "Name: " << this->name << "\n";
    std::cout << "HP: " << this->hp << "\n";
    std::cout << "EP: " << this->ep << "\n";
    std::cout << "AD: " << this->ad << std::endl;
}

DiamondTrap::DiamondTrap(void)
{
    std::cout << "DiamondTrap " << "Default constructor called" << std::endl;
    ClapTrap::name += "_clap_name";
    this->name = "unknown";
    this->ad = 30;
}

DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "DiamondTrap " << "String constructor called" << std::endl;
    ClapTrap::name = name + "_clap_name";
    this->name = name;
    this->ad = 30;
}
	    
DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
    std::cout << "DiamondTrap " << "Copy constructor called" << std::endl;
    *this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    std::cout << "DiamondTrap " << "Copy assignment operator called" << std::endl;
    ClapTrap::name = obj.name + "_clap_name";
    this->name = obj.name;
    this->hp = obj.hp;
    this->ep = obj.ep;
    this->ad = obj.ad;
    
    return *this;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->name <<  " is destroyed" << std::endl;
}