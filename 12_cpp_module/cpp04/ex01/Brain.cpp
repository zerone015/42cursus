#include <iostream>
#include "Brain.hpp"

std::string Brain::getIdea(int index)
{
    return (this->ideas[index]);
}

void    Brain::setIdea(int index, std::string idea)
{
    this->ideas[index] = idea;
}

Brain::Brain()
{
    std::cout << "Brain " << "Default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "one";
}

Brain::Brain(const Brain &src)
{
    std::cout << "Brain " << "Copy constructor called" << std::endl;
    *this = src;
}

Brain& Brain::operator=(const Brain &src)
{
    std::cout << "Brain " << "Copy assignment operator called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];

    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain " <<  "is destroyed" << std::endl;
}