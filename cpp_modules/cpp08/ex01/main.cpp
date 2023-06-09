#include <iostream>
#include <list>
#include "Span.hpp"

int main()
{
    std::cout << "------ sp ------" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "------ span ------" << std::endl;
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
    
    std::cout << "------ span2 range addNumber ------" << std::endl;
    std::list<int> a;
    a.push_back(1);
    a.push_back(24);
    a.push_back(34);

    Span span2(4);
    span2.addNumber(5);
    span2.addNumber(a.begin(), a.end());
    std::cout << span2.shortestSpan() << std::endl;
    std::cout << span2.longestSpan() << std::endl;
    try
    {
        span2.addNumber(a.begin(), a.end());
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "------ span3 range addNumber ------" << std::endl;
    Span span3(4);
    span3.addNumber(5);

    int arr[3];
    arr[0] = 44;
    arr[1] = 55;
    arr[2] = 100;
    span3.addNumber(arr, arr + 3);

    std::cout << span3.shortestSpan() << std::endl;
    std::cout << span3.longestSpan() << std::endl;
    try
    {
        span3.addNumber(arr, arr + 3);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << "------ capacity 0 test ------" << std::endl;
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
    
    std::cout << "------ assignment operator overloading ------" << std::endl;
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