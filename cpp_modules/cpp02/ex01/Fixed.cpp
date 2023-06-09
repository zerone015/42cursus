#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int Fixed::getRawBits() const
{
    return (value);
}

void    Fixed::setRawBits(const int raw)
{
    value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)value / (1 << bits)); 
}

int	Fixed::toInt(void) const
{
	return (value >> bits);
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    value = num << bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
	value = roundf(num * (1 << bits));
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

std::ostream& operator <<(std::ostream &outputStream, const Fixed &fixed)
{
	outputStream << fixed.toFloat();
	return (outputStream);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}