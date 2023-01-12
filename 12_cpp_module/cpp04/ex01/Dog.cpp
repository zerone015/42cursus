#include <iostream>
#include "Dog.hpp"

void    Dog::makeSound() const
{
    std::cout << "Dog~~~~~~" << std::endl;
}

Brain*   Dog::getBrain()
{
    return this->brain;
}

Dog::Dog()
{
    std::cout << "Dog " << "Default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &src)
{
    std::cout << "Dog " << "Copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = src;
}

Dog& Dog::operator=(const Dog &src)
{
    std::cout << "Dog " << "Copy assignment operator called" << std::endl;
    this->type = src.type;
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, src.brain->getIdea(i));

    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog " <<  "is destroyed" << std::endl;
    delete this->brain;
}