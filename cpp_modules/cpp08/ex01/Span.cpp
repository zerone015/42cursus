#include <algorithm>
#include <iostream>
#include "Span.hpp"

void    Span::addNumber(int num)
{
    if (_vector.size() >= _vector.capacity())
        throw std::out_of_range("can't store");
    _vector.push_back(num);
}

int     Span::shortestSpan() const
{
    if (_vector.size() < 2)
        throw std::range_error("can't find");
    std::vector<int> temp(_vector);
    std::sort(temp.begin(), temp.end());
    int min = temp[1] - temp[0];
    for (std::vector<int>::iterator it = temp.begin() + 2; it < temp.end(); it++)
    {
        if (min > *it - *(it - 1))
            min = *it - *(it - 1);
    }
    return min;
}

int     Span::longestSpan() const
{
    if (_vector.size() < 2)
        throw std::range_error("can't find");
    return *std::max_element(_vector.begin(), _vector.end()) - *std::min_element(_vector.begin(), _vector.end());
}

Span::Span()
{
    _vector.reserve(0);
}

Span::Span(unsigned int capacity)
{
    _vector.reserve(capacity);
}

Span::Span(const Span &src)
{
    *this = src;            
}

Span&   Span::operator=(const Span &src)
{
    _vector = src._vector;
    return *this;
}

Span::~Span(){}