#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << "\n";
		std::cerr << "Provide a seed please" << "\n";
		std::cerr << "Count value:" << COUNT << "\n";
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str(8);
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	std::cout << std::boolalpha;
	{
		std::cout << "----------- vector -----------" << "\n";

		ft::vector<std::string>::iterator it = vector_str.begin();

		for (unsigned int i = 0; i < vector_str.size(); ++i)
			it[i] = std::string((vector_str.size() - i), i + 65);
		for (unsigned int i = 0; i < vector_str.size(); ++i)
			std::cout << it[i] << "\n";
		std::cout << "-------------------------" << "\n";

		vector_str.push_back("string");
		std::cout << *(--vector_str.end()) << "\n";
		std::cout << "-------------------------" << "\n";

		vector_str.pop_back();
		std::cout << *(--vector_str.end()) << "\n";
		std::cout << "-------------------------" << "\n";

		vector_str.erase(vector_str.begin() + 1, vector_str.end());
		for (unsigned int i = 0; i < vector_str.size(); ++i)
			std::cout << it[i] << "\n";
		std::cout << "-------------------------" << "\n";
	}

	{
		std::cout << "----------- stack -----------" << "\n";
		std::cout << "empty: " << stack_int.empty() << "\n";
		std::cout << "size: " << stack_int.size() << "\n";

		stack_int.push(41);
		stack_int.push(29);
		stack_int.push(10);
		stack_int.push(42);

		std::cout << "empty: " << stack_int.empty() << "\n";
		std::cout << "size: " << stack_int.size() << "\n";

		while (!stack_int.empty())
		{
			std::cout << stack_int.top() << "\n";
			stack_int.pop();
		}
		std::cout << "empty: " << stack_int.empty() << "\n";
		std::cout << "size: " << stack_int.size() << "\n";
	}

	{
		std::cout << "----------- map -----------" << "\n";
		ft::map<int, int> map;
		ft::map<int, int>::iterator it;

		for (unsigned int i = 1; i <= 100; i++)
			map.insert(ft::make_pair(i, i));
		for (it = map.begin(); it != map.end(); it++)
			std::cout << it->second << "\n";
		it = map.begin();
		for (unsigned int i = 0; i < 49; i++)
			++it;
		for (; it != map.end(); it++)
			std::cout << it->second << "\n";
		map.begin()->second = 42;
		std::cout << map.begin()->second << "\n";
	}

	{
		std::cout << "----------- set -----------" << "\n";
		ft::set<int> set;
		ft::set<int>::iterator it;

		for (unsigned int i = 1; i <= 100; i++)
			set.insert(i);
		for (it = set.begin(); it != set.end(); it++)
			std::cout << *it << "\n";
		it = set.begin();
		for (unsigned int i = 0; i < 49; i++)
			++it;
		for (; it != set.end(); it++)
			std::cout << *it << "\n";
	}

	std::cout << "-----------------------------" << "\n";
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<"\n";
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << "\n";

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << "\n";
	return (0);
}