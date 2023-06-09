#include "Point.hpp"

Fixed   Point::getX() const
{
    return (this->x);
}

Fixed Point::getY() const
{
    return (this->y);
}

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &src)
{
    *this = src;
}

Point&  Point::operator=(const Point &src)
{
    const_cast<Fixed&>(this->x) = src.x;
    const_cast<Fixed&>(this->y) = src.y;
    
    return *this;
}

Point::~Point()
{

}