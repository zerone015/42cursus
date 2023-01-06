#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    private:
        std::string     name;
        unsigned int    hp;
        unsigned int    ep;
        unsigned int    ad;
    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &src);
        ClapTrap&   operator=(const ClapTrap &src);
        ~ClapTrap();
};

#endif