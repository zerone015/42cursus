#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    Point	a(8, 7);
	Point	b(5, 4);
	Point	c(2, 9);
	Point	p(5, 5);
	Point	p2(6, 5);

	if (bsp(a, b, c, p))
		std::cout << "p is in the triangle" << std::endl;
	else
		std::cout << "p is out of the triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "p2 is in the triangle" << std::endl;
	else
		std::cout << "p2 is out of the triangle" << std::endl;
	return  0;
}