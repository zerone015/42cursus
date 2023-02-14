#include <map>
#include <iostream>
int main()
{
    int *asdf = new int[5];
    std::map<char, int*> map;
    map.insert(std::pair<char, int*>('a', asdf));
    std::cout << map.erase('a') << std::endl;

    std::cout << map['a'] << std::endl;  
}