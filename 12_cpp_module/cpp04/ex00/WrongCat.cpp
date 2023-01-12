#include <iostream>
#include "WrongCat.hpp"

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat~~~~~~" << std::endl;
}

WrongCat::WrongCat()
{
    std::cout << "WrongCat " << "Default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
    std::cout << "WrongCat " << "Copy constructor called" << std::endl;
    *this = src;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
    std::cout << "WrongCat " << "Copy assignment operator called" << std::endl;
    this->type = src.type;

    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat " <<  "is destroyed" << std::endl;
}