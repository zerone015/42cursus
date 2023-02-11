#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
    private:
        std::vector<int>    _vector;
    public:
        void    addNumber(int num);
        template <typename InputIt>
        void    addNumber(InputIt begin, InputIt end)
        {
            if (_vector.size() + std::distance(begin, end) > _vector.capacity())
                throw std::out_of_range("can't store");
            _vector.insert(_vector.end(), begin, end);
        }
        int     shortestSpan() const;
        int     longestSpan() const;
        Span();
        Span(unsigned int capacity);
        Span(const Span &src);
        Span&   operator=(const Span &src);
        ~Span();
};

#endif