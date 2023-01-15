#include "Point.hpp"

float   getAbs(float val)
{
    if (val < 0)
        return (val * -1);
    return (val);
}

float   getTriangleSize(const Point a, const Point b, const Point c)
{
     Fixed tmp = Fixed(0.5f) * ((a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY()) - (a.getX() * c.getY() + c.getX() * b.getY() + b.getX() * a.getY()));
     
     return getAbs(tmp.toFloat());
}

bool    bsp(const Point a, const Point b, const Point c, const Point point)
{
    float abcSize = getTriangleSize(a, b, c);
	float abpSize = getTriangleSize(a, b, point);
	float acpSize = getTriangleSize(a, c, point);
	float bcpSize = getTriangleSize(b, c, point);
    
    if (!abcSize || !abpSize || !acpSize || !bcpSize)
		return (false);
	if (abcSize == abpSize + acpSize + bcpSize)
		return (true);
	return (false);
}