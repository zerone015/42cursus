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

Fixed&	Fixed::min(Fixed &obj1, Fixed &obj2)
{
    return (obj1 < obj2 ? obj1 : obj2);
}

const Fixed&	Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    return (obj1 < obj2 ? obj1 : obj2);
}

Fixed&	Fixed::max(Fixed &obj1, Fixed &obj2)
{
    return (obj1 > obj2 ? obj1 : obj2);
}

const Fixed&	Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
    return (obj1 > obj2 ? obj1 : obj2);
}

Fixed::Fixed()
{
    value = 0;
}

Fixed::Fixed(const int num)
{
    value = num << bits;
}

Fixed::Fixed(const float num)
{
	value = roundf(num * (1 << bits));
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed&  Fixed::operator=(const Fixed &src)
{
    value = src.getRawBits();
    return (*this);
}

bool    Fixed::operator>(const Fixed &obj) const
{
	return (bits > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed &obj) const
{
	return (bits < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed &obj) const
{
	return (bits >= obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed &obj) const
{
	return (bits <= obj.getRawBits());
}

bool	Fixed::operator==(const Fixed &obj) const
{
	return (bits == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return (bits != obj.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	value++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);

	value++;
	return (ret);
}

Fixed&	Fixed::operator--(void)
{
	value--;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);

	value--;
	return (ret);
}

std::ostream& operator <<(std::ostream &outputStream, const Fixed &fixed)
{
	outputStream << fixed.toFloat();
	return (outputStream);
}

Fixed::~Fixed()
{
	
}