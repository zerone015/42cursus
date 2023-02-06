#include "iter.hpp"

int main()
{
    int         intArr[5] = {0, 1, 2, 3, 4};
    std::string strArr[5] = {"qq", "ww", "ee", "rr", "tt"};

    iter(intArr, 5, display);
    iter(strArr, 5, display);
    return 0;
}