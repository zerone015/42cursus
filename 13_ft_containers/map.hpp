#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include "pair.hpp"
# include "iterator.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T>>>
    class map
    {
        public:
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef ft::pair<const key_type, mapped_type>                   value_type;
            typedef Compare                                                 key_compare;
            //typedef value_compare; 대기   ..
            typedef Allocator                                               allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            // typedef iterator; 대기..
            // typedef const_iterator; 대기..
            typedef ft::reverse_iterator<iterator>                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef typename allocator_type::size_type                      size_type;
    };
}

#endif