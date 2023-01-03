#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
}

void    Harl::debug()
{
    std::cout << "[ DEBUG ]" << "\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << "\n";
    std::cout << "I really do!" << "\n" << std::endl;
}

void    Harl::info()
{
    std::cout << "[ INFO ]" << "\n";
    std::cout << "I cannot believe adding extra bacon costs more money." << "\n";
    std::cout << "You didn’t put enough bacon in my burger!" << "\n";
    std::cout << "If you did, I wouldn’t be asking for more!" << "\n" << std::endl;
}

void    Harl::warning()
{
    std::cout << "[ WARNING ]" << "\n";
    std::cout << "I think I deserve to have some extra bacon for free." << "\n";
    std::cout << "I’ve been coming for years whereas you started working here since last month." << "\n" << std::endl;
}

void    Harl::error()
{
    std::cout << "[ ERROR ]" << "\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << "\n" << std::endl;
}

void    Harl::complain(std::string level)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            break ;
    }
    switch (i)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}