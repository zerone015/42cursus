#include <iostream>
#include "utils.hpp"

std::string    safe_getline(void)
{
    std::string ret;

    std::cout << "> ";
    std::getline(std::cin, ret);
    if (std::cin.eof())
        exit(EXIT_FAILURE);
    return (ret);
}

int    safe_cin(void)
{
    int ret;

    std::cout << "> ";
    std::cin >> ret;
    if (std::cin.eof())
        exit(EXIT_FAILURE);
    return (ret);
}

std::string str_to_upper(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
    return (str);
}

std::string trim_whitespace(std::string str)
{
    size_t  i;

    for (i = 0; i < str.length(); i++)
    {
        if (!isspace(str[i]))
            break ;
    }
    str.erase(0, i);
    for (i = str.length() - 1; i < str.length(); i--)
    {
        if (!isspace(str[i]))
            break ;
    }
    str.erase(i + 1, str.length() - (i + 1));
    return (str);
}