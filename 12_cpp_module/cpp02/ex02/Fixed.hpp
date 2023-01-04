#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 value;
        static const int    bits = 8;
    public:
        int     getRawBits() const;
        void    setRawBits(const int raw);
        float	toFloat(void) const;
        int	    toInt(void) const;
        static Fixed	    &min(Fixed &obj1, Fixed &obj2);
        static const Fixed	&min(const Fixed &obj1, const Fixed &obj2);
        static Fixed	    &max(Fixed &obj1, Fixed &obj2);
        static const Fixed	&max(const Fixed &obj1, const Fixed &obj2);
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &src);
        Fixed&  operator=(const Fixed &src);
        bool	operator>(const Fixed &obj) const;
        bool	operator<(const Fixed &obj) const;
        bool	operator>=(const Fixed &obj) const;
        bool	operator<=(const Fixed &obj) const;
        bool	operator==(const Fixed &obj) const;
        bool	operator!=(const Fixed &obj) const;
        Fixed	operator+(const Fixed &obj) const;
        Fixed	operator-(const Fixed &obj) const;
        Fixed	operator*(const Fixed &obj) const;
        Fixed	operator/(const Fixed &obj) const;
        Fixed	&operator++(void);
        Fixed	operator++(int);
        Fixed	&operator--(void);
        Fixed	operator--(int);
        ~Fixed();
};

std::ostream& operator <<(std::ostream &outputStream, const Fixed &fixed);

#endif