#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

template <typename T, typename Allocator = std::allocator<T>>
class Vector 
{
    private:
        T   *_data;
        int _capacity;
        int _length;
    public:
        Vector() : _capacity(1), _length(0) {Allocator<T> allocator; _data = allocator.allocate(1);}
        Vector(const Vector &src) {*this = src}
        Vector &operator=(const Vector &src);
        ~Vector();
};

#endif