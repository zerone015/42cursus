#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
    private:
        std::string levels[4];
        void        debug();
        void        info();
        void        warning();
        void        error();
    public:
        void    complain(std::string level);
        Harl();
};

#endif