#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{

template <typename T, typename Allocator = std::allocator<T>>
class vector 
{
    public:
        typedef Allocator                   allocator_type;
        typedef T                           value_type;
        typedef allocator_type::size_type   size_type;
    private:
        Allocator   allocator;
};

}

#endif