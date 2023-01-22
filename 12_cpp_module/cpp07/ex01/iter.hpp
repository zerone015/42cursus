#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void    iter(T array[], size_t len, void (*f)(T &))
{
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}

template <typename T>
void    display(T &a)
{
    std::cout << a << "\n";
}

#endif