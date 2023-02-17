
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
#include "common.hpp"
#include <list>

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";
	printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	printSize(mp);
	ft_erase(mp, mp.begin(), mp.end());

	return (0);
}

// #include <iostream>
// #include <string>
// #include <deque>
// #if 0 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include "map.hpp"
// 	#include "stack.hpp"
// 	#include "vector.hpp"
// #endif

// #include <stdlib.h>


// int main() {
// 	ft::vector<int> vct(10);
// 	ft::vector<int> vct2;
// 	ft::vector<int> vct3;

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = (vct.size() - i) * 3;
// 	printSize(vct);

// 	vct2.insert(vct2.end(), 42);
// 	// vct2.insert(vct2.begin(), 2, 21);
// 	// printSize(vct2);

// 	// vct2.insert(vct2.end() - 2, 42);
// 	// printSize(vct2);

// 	// vct2.insert(vct2.end(), 2, 84);
// 	// printSize(vct2);

// 	// vct2.resize(4);
// 	// printSize(vct2);

// 	// vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
// 	// vct.clear();
// 	// printSize(vct2);

// 	// printSize(vct);

// 	// for (int i = 0; i < 5; ++i)
// 	// 	vct3.insert(vct3.end(), i);
// 	// vct3.insert(vct3.begin() + 1, 2, 111);
// 	// printSize(vct3);

// 	return (0);

// }