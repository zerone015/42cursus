#include <iostream>
#include "Cat.hpp"

void    Cat::makeSound() const
{
    std::cout << "Cat~~~~~~" << std::endl;
}

Cat::Cat()
{
    std::cout << "Cat " << "Default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &src)
{
    std::cout << "Cat " << "Copy constructor called" << std::endl;
    *this = src;
}

Cat& Cat::operator=(const Cat &src)
{
    std::cout << "Cat " << "Copy assignment operator called" << std::endl;
    this->type = src.type;

    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat " <<  "is destroyed" << std::endl;
}