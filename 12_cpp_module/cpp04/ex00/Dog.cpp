#include <iostream>
#include "Dog.hpp"

void    Dog::makeSound() const
{
    std::cout << "Dog~~~~~~" << std::endl;
}

Dog::Dog()
{
    std::cout << "Dog " << "Default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &src)
{
    std::cout << "Dog " << "Copy constructor called" << std::endl;
    *this = src;
}

Dog& Dog::operator=(const Dog &src)
{
    std::cout << "Dog " << "Copy assignment operator called" << std::endl;
    this->type = src.type;

    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog " <<  "is destroyed" << std::endl;
}