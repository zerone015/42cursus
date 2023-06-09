#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> vector;
        vector.push_back(1);
        vector.push_back(2);
        vector.push_back(10);
        std::cout << "vector: " << *easyfind(vector, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    try
    {
        std::list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(9);
        std::cout << "list: " << *easyfind(list, 4) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    try
    {
        std::deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);
        std::cout << "deque: " << *easyfind(deque, 4) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}