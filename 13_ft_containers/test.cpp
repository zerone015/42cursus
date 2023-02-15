#include <iostream>
#include "vector.hpp"
#include <vector>

int main()
{
    {
        ft::vector<int> vector;

        vector.push_back(1);
        vector.push_back(2);
        vector.push_back(3);
        vector.push_back(4);

        ft::vector<int>::iterator a = vector.begin();
        ft::vector<int>::const_iterator b = static_cast<ft::random_access_iterator<const int> >(vector.begin());
       
    }
    {
        std::vector<int> vector;

        vector.push_back(1);
        vector.push_back(2);
        vector.push_back(3);
        vector.push_back(4);

        std::vector<int>::iterator a = vector.begin();
        std::vector<int>::const_iterator b = vector.begin();
    }
    


}