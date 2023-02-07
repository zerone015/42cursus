#include <iostream>
#include <list>
#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span span(10000);
    for (int i = 1; i <= 9998; i++)
        span.addNumber(i);
    span.addNumber(9998);
    span.addNumber(100000);
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;
    try
    {
        span.addNumber(-1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    
    std::list<int> a;
    a.push_back(1);
    a.push_back(24);
    a.push_back(34);

    Span<std::list<int>::iterator> span2(3);
    span2.addNumber(a.begin(), a.end());
    std::cout << span2.shortestSpan() << std::endl;
    std::cout << span2.longestSpan() << std::endl;
        
    Span test;
    try
    {
        test.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        test.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        test.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    test = span;
    try
    {
        test.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << test.shortestSpan() << "\n";
    std::cout << test.longestSpan() << "\n";
    return 0;
}