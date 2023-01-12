#include <iostream>
#include "WrongAnimal.hpp"

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal~~~~~~~~~~" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal " << "Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "WrongAnimal " << "Copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "WrongAnimal " << "Copy assignment operator called" << std::endl;
    this->type = src.type;

    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal " <<  "is destroyed" << std::endl;
}