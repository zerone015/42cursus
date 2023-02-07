#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

template <typename InputIt = std::vector<int>::iterator>
class Span
{
    private:
        std::vector<int>    _vector;
    public:
        void    addNumber(int num);
        void    addNumber(InputIt begin, InputIt end);
        int     shortestSpan() const;
        int     longestSpan() const;
        Span();
        Span(unsigned int capacity);
        Span(const Span &src);
        Span&   operator=(const Span &src);
        ~Span();
};

# include "Span.tpp"

#endif