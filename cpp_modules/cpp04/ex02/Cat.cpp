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
    this->brain = new Brain();
}

Cat::Cat(const Cat &src)
{
    std::cout << "Cat " << "Copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = src;
}

Cat& Cat::operator=(const Cat &src)
{
    std::cout << "Cat " << "Copy assignment operator called" << std::endl;
    this->type = src.type;
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, src.brain->getIdea(i));

    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat " <<  "is destroyed" << std::endl;
    delete this->brain;
}