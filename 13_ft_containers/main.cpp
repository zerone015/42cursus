#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

#include <stdlib.h>

#define T_SIZE_TYPE typename ft::vector<T>::size_type

template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int main() {
	ft::vector<int> vct(10);
	ft::vector<int> vct2;
	ft::vector<int> vct3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	printSize(vct);

	vct2.insert(vct2.end(), 42);
	// vct2.insert(vct2.begin(), 2, 21);
	// printSize(vct2);

	// vct2.insert(vct2.end() - 2, 42);
	// printSize(vct2);

	// vct2.insert(vct2.end(), 2, 84);
	// printSize(vct2);

	// vct2.resize(4);
	// printSize(vct2);

	// vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	// vct.clear();
	// printSize(vct2);

	// printSize(vct);

	// for (int i = 0; i < 5; ++i)
	// 	vct3.insert(vct3.end(), i);
	// vct3.insert(vct3.begin() + 1, 2, 111);
	// printSize(vct3);

	return (0);

}