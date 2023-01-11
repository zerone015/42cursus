#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        void    highFivesGuys(void);
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
        FragTrap& operator=(const FragTrap &src);
        ~FragTrap();
};

#endif