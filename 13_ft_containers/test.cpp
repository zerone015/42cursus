# include "map.hpp"
# include <iostream>
int main()
{
    ft::map<char, int> map;

    map.insert(ft::pair<char, int>('a', 12));
    std::cout << map['a'] << std::endl;
    map['a'] = 10;
    std::cout << map['a'] << std::endl;
    std::cout << map.size() << std::endl;

}