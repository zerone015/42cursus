#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon      *weapon;
    public:
        void    setWeapon(Weapon &weapon);
        void    attack() const;
        HumanB();
        HumanB(std::string name);
};

#endif