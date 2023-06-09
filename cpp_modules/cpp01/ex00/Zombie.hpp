#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string name;
    public:
        void    setName(std::string name);
        void    announce(void) const;
        ~Zombie(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif