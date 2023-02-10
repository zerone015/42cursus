#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "iterator.hpp"

namespace ft
{

template <typename T, typename Allocator = std::allocator<T>>
class vector 
{
    public:
        typedef Allocator                                               allocator_type;
        typedef T                                                       value_type;
        typedef typename allocator_type::size_type                      size_type;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        //iterator...
    private:
        Allocator   allocator;
};

}

#endif