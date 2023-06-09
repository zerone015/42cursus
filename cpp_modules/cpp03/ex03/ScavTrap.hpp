#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &src);
        ScavTrap& operator=(const ScavTrap &src);
        ~ScavTrap();
        void    attack(const std::string& target);
        void    guardGate();
};

#endif