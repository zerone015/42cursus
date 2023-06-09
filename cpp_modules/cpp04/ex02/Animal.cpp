#include <iostream>
#include "Animal.hpp"

std::string Animal::getType() const
{
    return (this->type);
}

Animal::Animal()
{
    std::cout << "Animal " << "Default constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
    std::cout << "Animal " << "Copy constructor called" << std::endl;
    *this = src;
}

Animal& Animal::operator=(const Animal &src)
{
    std::cout << "Animal " << "Copy assignment operator called" << std::endl;
    this->type = src.type;

    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal " <<  "is destroyed" << std::endl;
}