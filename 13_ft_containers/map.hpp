#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include "pair.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "rb_tree.hpp"

namespace ft
{
    template <typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key                                                                             key_type;
            typedef T                                                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>                                           value_type;
            typedef Compare                                                                         key_compare;
            typedef Allocator                                                                       allocator_type;
            typedef typename allocator_type::reference                                              reference;
            typedef typename allocator_type::const_reference                                        const_reference;
            typedef typename allocator_type::pointer                                                pointer;
            typedef typename allocator_type::const_pointer                                          const_pointer;
            typedef typename ft::rb_tree<value_type, key_compare, allocator_type>::iterator         iterator;
            typedef typename ft::rb_tree<value_type, key_compare, allocator_type>::const_iterator   const_iterator;
            typedef ft::reverse_iterator<iterator>                                                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                                            const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type                         difference_type;
            typedef typename allocator_type::size_type                                              size_type;

            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                protected:
                    Compare comp;

                    value_compare(Compare c) : comp(c) {}
                public:
                    bool operator()(const value_type& lhs, const value_type& rhs) const
                    {
                        return comp(lhs.first, rhs.first);
                    }
            };
            private:
                allocator_type                                          _allocator;
                key_compare                                             _comp;
                ft::rb_tree<value_type, key_compare, allocator_type>    _tree;
            public:
                explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _comp(comp), _tree(ft::rb_tree<value_type, key_compare, allocator_type>()) {}
                template <typename InputIterator>
                map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _comp(comp), _tree(ft::rb_tree<value_type, key_compare, allocator_type>())
                {
                    for (; first != last; first++)
                        _tree.insert(*first);
                }
                map(const map& src) 
                {
                    *this = src;
                }

    };
}

#endif