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
            class   value_compare;

            typedef Key                                                                             key_type;
            typedef T                                                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>                                           value_type;
            typedef Compare                                                                         key_compare;
            typedef Allocator                                                                       allocator_type;
            typedef typename allocator_type::reference                                              reference;
            typedef typename allocator_type::const_reference                                        const_reference;
            typedef typename allocator_type::pointer                                                pointer;
            typedef typename allocator_type::const_pointer                                          const_pointer;
            typedef typename ft::rb_tree<value_type, value_compare, allocator_type>::iterator       iterator;
            typedef typename ft::rb_tree<value_type, value_compare, allocator_type>::const_iterator const_iterator;
            typedef ft::reverse_iterator<iterator>                                                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                                            const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type                         difference_type;
            typedef typename allocator_type::size_type                                              size_type;

            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                protected:
                    Compare comp;
                public:
                    value_compare(Compare c) : comp(c) {}
                    bool operator()(const value_type& lhs, const value_type& rhs) const
                    {
                        return comp(lhs.first, rhs.first);
                    }
            };
            private:
                allocator_type                                          _allocator;
                key_compare                                             _comp;
                ft::rb_tree<value_type, value_compare, allocator_type>  _tree;
            public:
                // default constructor
                explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _comp(comp), _tree(alloc, value_compare(_comp)) {}
                // range constructor
                template <typename InputIterator>
                map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _comp(comp), _tree(alloc, value_compare(_comp))
                {
                    for (; first != last; first++)
                        _tree.insert(*first);
                }
                // copy constructor
                map(const map& src) 
                {
                    *this = src;
                }
                // copy assignment operator
                map& operator=(const map& src)
                {
                    _allocator = src._allocator;
                    _comp = src._comp;
                    _tree.clear();
                    for (iterator it = src.begin(); it != src.end(); it++)
                        _tree.insert(*it);
                    return *this;
                }
                // Iterators
                iterator begin()
                {
                    if (_tree.size() == 0)
                        return iterator();
                    return iterator(_tree.getMinNode(), false);
                }
                const_iterator begin() const
                {
                    if (_tree.size() == 0)
                        return const_iterator();
                    return const_iterator(_tree.getMinNode(), false);
                }
                iterator end()
                {
                    if (_tree.size() == 0)
                        return iterator();
                    return iterator(_tree.getMaxNode(), true);
                }
                const_iterator end() const
                {
                    if (_tree.size() == 0)
                        return const_iterator();
                    return const_iterator(_tree.getMaxNode(), true);
                }
                reverse_iterator rbegin()
                {
                    return reverse_iterator(end());
                }
                const_reverse_iterator rbegin() const
                {
                    return const_reverse_iterator(end());
                }
                reverse_iterator rend()
                {
                    return reverse_iterator(begin());
                }
                const_reverse_iterator rend() const
                {
                    return const_reverse_iterator(begin());
                }

                // Capacity
                bool empty() const
                {
                    return _tree.size() == 0 ? true : false;
                }
                size_type size() const
                {
                    return _tree.size();
                }
                size_type max_size() const
                {
                    return _allocator.max_size();
                }

    };
}

#endif