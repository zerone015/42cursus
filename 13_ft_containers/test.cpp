#include <vector>
#include <iostream>
#include "vector.hpp"
int main()
{
    std::vector<int> vector(3, 96);
    std::vector<int> vector2(3, 11);

    std::swap(vector, vector2);
    // ft::vector<int>::iterator a = vector.begin();
    // std::cout << "size: " << vector.size() << std::endl;
    // std::cout << "capacity: " << vector.capacity() << std::endl;
    // vector.insert(vector.begin(), 1, 4);
    // std::cout << "size: " << vector.size() << std::endl;
    // std::cout << "capacity: " << vector.capacity() << std::endl;
    // std::cout << "max_size: " << vector.max_size() << std::endl;
    // vector.push_back(4);
    // vector.push_back(4);
    // vector.push_back(4);
    // std::cout << "max_size: " << vector.max_size() << std::endl;
    // std::cout << "size: " << vector.size() << std::endl;
    // std::cout << "capacity: " << vector.capacity() << std::endl;
    std::vector<int>::iterator first = vector.begin();
    std::vector<int>::iterator last = vector.end();
    while (first != last)
        std::cout << *first++ << std::endl;
}