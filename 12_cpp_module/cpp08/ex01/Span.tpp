template <typename InputIt>
void    Span<InputIt>::addNumber(int num)
{
    if (_vector.size() >= _vector.capacity())
        throw std::out_of_range("can't store");
    _vector.push_back(num);
}

template <typename InputIt>
void    Span<InputIt>::addNumber(InputIt begin, InputIt end)
{
    int add_size = 0;
    for (InputIt it = begin; it < end; it++)
        add_size++;
    if (_vector.size() + add_size >= _vector.capacity())
        throw std::out_of_range("can't store");
    while (begin < end)
    {
        _vector.push_back(*begin);
        begin++;
    }
}

template <typename InputIt>
int     Span<InputIt>::shortestSpan() const
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

template <typename InputIt>
int     Span<InputIt>::longestSpan() const
{
    if (_vector.size() < 2)
        throw std::range_error("can't find");
    return *std::max_element(_vector.begin(), _vector.end()) - *std::min_element(_vector.begin(), _vector.end());
}

template <typename InputIt>
Span<InputIt>::Span()
{
    _vector.reserve(0);
}

template <typename InputIt>
Span<InputIt>::Span(unsigned int capacity)
{
    _vector.reserve(capacity);
}

template <typename InputIt>
Span<InputIt>::Span(const Span &src)
{
    *this = src;            
}

template <typename InputIt>
Span<InputIt>&   Span<InputIt>::operator=(const Span &src)
{
    _vector = src._vector;
    return *this;
}

template <typename InputIt>
Span<InputIt>::~Span(){}