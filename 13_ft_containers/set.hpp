#ifndef SET_HPP
#define SET_HPP

#include <functional>
#include <memory>
#include "rb_tree.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"

namespace ft
{
    template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>>
    class set
    {
    public:
        typedef Key key_type;
        typedef Key value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Allocator allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::rb_tree<value_type, key_compare, allocator_type>::iterator iterator;
        typedef typename ft::rb_tree<value_type, key_compare, allocator_type>::const_iterator const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename allocator_type::size_type size_type;

    private:
        allocator_type _allocator;
        key_compare _comp;
        ft::rb_tree<value_type, key_compare, allocator_type> _tree;

    public:
        // default constructor
        explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _comp(comp), _tree(alloc, value_compare(comp)) {}
        // range constructor
        template <class InputIterator>
        set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _allocator(alloc), _comp(comp), _tree(alloc, value_compare(comp))
        {
            for (; first != last; ++first)
                _tree.insert(*first);
        }
        // copy constructor
        set(const set &x) : _allocator(src._allocator), _comp(src._comp), _tree(_allocator, value_compare(_comp))
        {
            for (const_iterator it = src.begin(); it != src.end(); ++it)
                _tree.insert(*it);
        }
        // copy assignment operator
        set &operator=(const set &x)
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
            return _tree.getMaxSize();
        }

        // Modifiers
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            ft::pair<iterator, bool> ret;

            ret.second = _tree.insert(val);
            ret.first = iterator(_tree.get(val), false);
            return ret;
        }
        iterator insert(iterator position, const value_type &val)
        {
            static_cast<void>(position);
            _tree.insert(val);
            return iterator(_tree.get(val), false);
        }
        template <typename InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            for (; first != last; ++first)
                _tree.insert(*first);
        }
        void erase(iterator position)
        {
            _tree.remove(*position);
        }
        size_type erase(const key_type &key)
        {
            return _tree.remove(key_type);
        }
        void erase(iterator first, iterator last)
        {
            iterator cur;

            while (first != last)
            {
                cur = first;
                ++first;
                _tree.remove(*cur);
            }
        }
        void swap(map &x)
        {
            _tree.swap(x._tree);
        }
        void clear()
        {
            _tree.clear();
        }

        // Observers
        key_compare key_comp() const
        {
            return key_compare(_comp);
        }
        value_compare value_comp() const
        {
            return value_compare(_comp);
        }
    };
}

#endif