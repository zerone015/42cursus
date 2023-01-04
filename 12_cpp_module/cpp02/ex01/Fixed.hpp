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
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &src);
        Fixed&  operator=(const Fixed &src);
        ~Fixed();
};

std::ostream& operator <<(std::ostream &outputStream, const Fixed &fixed);

#endif