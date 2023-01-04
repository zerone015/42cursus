#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int                 value;
        static const int    fractional = 8;
    public:
        int     getRawBits() const;
        void    setRawBits(const int raw);
        Fixed();
        Fixed(const Fixed &src);
        Fixed&  operator=(const Fixed &src);
        ~Fixed();
};

#endif