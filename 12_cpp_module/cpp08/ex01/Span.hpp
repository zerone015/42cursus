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
            int add_size = 0;
            for (InputIt it = begin; it != end; it++)
                add_size++;
            if (_vector.size() + add_size > _vector.capacity())
                throw std::out_of_range("can't store");
            for (; begin != end; begin++)
                _vector.push_back(*begin);
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