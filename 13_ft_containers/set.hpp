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
            typedef Key                                                                             key_type;
            typedef Key                                                                             value_type;
            typedef Compare                                                                         key_compare;
            typedef Compare                                                                         value_compare;
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
        private:
            allocator_type                                          _allocator;
            key_compare                                             _comp;
            ft::rb_tree<value_type, key_compare, allocator_type>    _tree;
        public:
            // default constructor
            explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _comp(comp), _tree(alloc, value_compare(comp)) {}            
            // range constructor
            template <class InputIterator>  
            set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _comp(comp), _tree(alloc, value_compare(comp))
            {
                for (; first != last; ++first)
                    _tree.insert(*first);
            }
            // copy constructor
            set(const set& x) : _allocator(src._allocator), _comp(src._comp), _tree(_allocator, value_compare(_comp))
            {
                for (const_iterator it = src.begin(); it != src.end(); ++it)
                    _tree.insert(*it);
            }
            // copy assignment operator
            set& operator=(const set& x)
            {
                if (this = &src)
                    return *this;
                _allocator = src._allocator;
                _comp = src._comp;
                _tree.clear();
                for (const_iterator it = src.begin(); it != src.end(); ++it)
                    _tree.insert(*it);
                return *this;
            }




    };
}

#endif