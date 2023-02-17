#ifndef SET_HPP
# define SET_HPP

# include <functional>
# include <memory>
# include "rb_tree.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
    template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > 
    class set
    {
        public:
            typedef Key                                                                         key_type;
            typedef Key                                                                         value_type;
            typedef Compare                                                                     key_compare;
            typedef Compare                                                                     value_compare;
            typedef Allocator                                                                   allocator_type;
            typedef typename allocator_type::reference                                          reference;
            typedef typename allocator_type::const_reference                                    const_reference;
            typedef typename allocator_type::pointer                                            pointer;
            typedef typename allocator_type::const_pointer                                      const_pointer;
            typedef typename ft::rb_tree<value_type, Compare, allocator_type>::iterator         iterator;
            typedef typename ft::rb_tree<value_type, Compare, allocator_type>::const_iterator   const_iterator;
            typedef ft::reverse_iterator<iterator>                                              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                                        const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type                     difference_type;
            typedef typename allocator_type::size_type                                          size_type;
    };
}

#endif