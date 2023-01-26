#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
    private:
        T               *_array;
        unsigned int    _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        Array&      operator=(const Array &src);
        T&          operator[](unsigned int idx);
        const T&    operator[](unsigned int idx) const;
        ~Array();
        unsigned int    size() const;
};

# include "Array.tpp"

#endif