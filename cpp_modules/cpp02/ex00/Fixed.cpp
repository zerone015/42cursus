#include <iostream>
#include "Fixed.hpp"

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void    Fixed::setRawBits(const int raw)
{
    value = raw;
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed&  Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = src.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}