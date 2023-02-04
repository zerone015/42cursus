#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
    private:
        std::vector<int>    _vector;
    public:
        void    addNumber(int num);
        int     shortestSpan();
        int     longestSpan();
        Span();
        Span(unsigned int capacity);
        Span(const Span &src);
        Span&   operator=(const Span &src);
        ~Span();
};

#endif