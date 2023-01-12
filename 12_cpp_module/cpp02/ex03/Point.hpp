#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Fixed   getX();
        Fixed   getY();
        Point();
        Point(const float x, const float y);
        Point(const Point &src);
        Point&  operator=(const Point &src);
        ~Point();
};

bool    bsp(const Point a, const Point b, const Point c, const Point point);

#endif