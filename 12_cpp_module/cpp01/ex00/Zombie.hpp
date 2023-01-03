#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string name;
        Zombie(void);
    public:
        void    announce(void) const;
        Zombie(std::string name);
        ~Zombie(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif