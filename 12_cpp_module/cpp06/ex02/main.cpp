#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "pointer A" <<std::endl;
	if (dynamic_cast<B *>(p) != NULL)
		std::cout << "pointer B" <<std::endl;
	if (dynamic_cast<C *>(p) != NULL)
		std::cout << "pointer C" <<std::endl;
}

void identify(Base& p)
{
	try 
    {
		A &a = dynamic_cast<A &>(p);
		std::cout << "reference A" <<std::endl;
		static_cast<void>(a);
	}
	catch(std::exception &){}
	try 
    {
		B &b = dynamic_cast<B &>(p);
		std::cout << "reference B" <<std::endl;
		static_cast<void>(b);
	}
	catch(std::exception &){}
	try 
    {
        C &c = dynamic_cast<C &>(p);
		std::cout << "reference C" <<std::endl;
		static_cast<void>(c);
	}
	catch(std::exception &){}
}

int main()
{
	Base *r = generate();

	identify(*r);
	identify(r);

	delete r;
    return 0;
}