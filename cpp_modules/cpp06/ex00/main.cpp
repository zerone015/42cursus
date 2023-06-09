#include <iostream>
#include "ScalarTypes.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments" << std::endl;
        return 1;
    }
    ScalarTypes a(argv[1]);
    a.convert();
    return 0;
}