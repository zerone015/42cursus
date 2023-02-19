#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "distance.hpp"
# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"

namespace ft
{
    template <typename T, typename Allocator = std::allocator<T> >
    class vector 
    {
        public:
            typedef T                                                       value_type;
            typedef Allocator                                               allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef ft::random_access_iterator<value_type>                  iterator;
            typedef ft::random_access_iterator<const value_type>            const_iterator;
            typedef ft::reverse_iterator<iterator>                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef typename allocator_type::size_type                      size_type;
        private:
            allocator_type  _allocator;
            pointer         _array;
            size_type       _capacity;
            size_type       _size;
        private:
            void _shiftLeft(iterator position, size_type n)
            {
                if (_size == 0)
                    return ;
                for (iterator it = position; it != this->end() - n; ++it)
                    *it = *(it + n);
            }
            void _shiftRight(iterator position, size_type n)
            {
                if (_size == 0)
                    return ;
                for (iterator it = this->end() - 1; it >= position; --it)
                    *(it + n) = *it;
            }
            void _destroy(iterator position)
            {
                _allocator.destroy(&(*position));
            }
            void _destroy(iterator first, iterator last)
            {
                while (first != last)
                {
                    _allocator.destroy(&(*first));
                    ++first;
                }
            }
            template <typename Type>
            void	_swap(Type &a, Type &b)
            {
                Type tmp;

                tmp = a;
                a = b;
                b = tmp;
            }
            size_type _findAllocSize(size_type n)
            {
                size_type ret = _capacity == 0 ? 1 : _capacity;
                while (ret < n)
                    ret = ret << 1;
                return ret;
            }
            void _reserve(size_type n)
            {
                pointer new_array = _allocator.allocate(n);
                for (size_type i = 0; i < _size; ++i)
                    _allocator.construct(new_array + i, *(_array + i));
                for (size_type i = 0; i < _size; ++i)
                    _allocator.destroy(_array + i);
                _allocator.deallocate(_array, _capacity);
                _capacity = n;
                _array = new_array;
            }
        public:
            // default constructor
            explicit vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _array(NULL), _capacity(0), _size(0) {}
            // fill constructor
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _capacity(n), _size(n)
            {
                if (_capacity > this->max_size())
                        throw std::length_error("vector");
                _array = _allocator.allocate(_capacity);
                for (size_type i = 0; i < n; ++i)
                    _allocator.construct(_array + i, val);
            }
            // range constructor
            template <typename InputIterator>
            vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()) : _allocator(alloc)
            {
                _capacity = ft::distance(first, last);
                _array = _allocator.allocate(_capacity);
                _size = 0;
                this->insert(this->end(), first, last);
            }
            // copy constructor
            vector(const vector& src) : _allocator(src.get_allocator())
            {
                _capacity = src.capacity();
                _array = _allocator.allocate(_capacity);
                _size = 0;
                this->insert(this->end(), src.begin(), src.end());
            }
            // destructor
            ~vector()
            {
                this->clear();
                _allocator.deallocate(_array, _capacity);
            }
            // copy assignment operator
            vector& operator=(const vector& src)
            {
                if (this == &src)
                    return *this;

                this->clear();
                this->insert(this->end(), src.begin(), src.end());
                return *this;
            }

            // Iterators
            iterator begin()
            {
                return iterator(_array);
            }
            const_iterator begin() const
            {
                return const_iterator(_array);
            }
            iterator end()
            {
                return iterator(_array + _size);
            }
            const_iterator end() const
            {
                return const_iterator(_array + _size);
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(this->end());
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(this->end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(this->begin());
            }
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(this->begin());
            }

            // Capacity
            size_type size() const
            {
                return _size;
            }
            size_type max_size() const
            {
                return _allocator.max_size();
            }
            void resize(size_type n, value_type val = value_type())
            {
                if (n > _size)
                {
                    this->insert(this->end(), n - _size, val);
                }
                else if (n < _size)
                {
                    for (size_type i = n; i < _size; ++i)
                        _allocator.destroy(_array + i);
                    _size = n;
                }
            }
            bool empty() const
            {
                return _size == 0 ? true : false;
            }
            size_type capacity() const
            {
                return _capacity;
            }
            void reserve(size_type n)
            {
                if (n > this->max_size())
                    throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
                if (n > _capacity)
                    this->_reserve(n);
            }
            
            // Element access
            reference operator[](size_type n)
            {
                return _array[n];
            }
            const_reference operator[] (size_type n) const
            {
                return _array[n];
            }
            reference at(size_type n)
            {
                if (n >= _size)
                    throw std::out_of_range("vector");
                return operator[](n);
            }
            const_reference at(size_type n) const
            {
                if (n >= _size)
                    throw std::out_of_range("vector");
                return operator[](n);
            }
            reference front()
            {
                return _array[0];
            }
            const_reference front() const
            {
                return _array[0];
            }
            reference back()
            {
                return _array[_size - 1];
            }
            const_reference back() const
            {
                return _array[_size - 1];
            }
            value_type* data()
            {
                return _array;
            }
            const value_type* data() const
            {
                return _array;
            }

            // Modifiers
            template <class InputIterator>
            void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
            {
                this->clear();
                
                size_type n = ft::distance(first, last);

                if (_capacity < n)
                {
                    _allocator.deallocate(_array, _capacity);
                    _array = NULL;
                    _capacity = 0;
                }
                insert(this->end(), first, last);
            }
            void assign(size_type n, const value_type& val)
            {
                this->clear();

                if (_capacity < n)
                {
                    _allocator.deallocate(_array, _capacity);
                    _array = NULL;
                    _capacity = 0;
                }
                this->insert(this->end(), n, val);
            }
            void push_back(const value_type& val)
            {
                if (_size == _capacity)
                    this->_reserve(_findAllocSize(_size + 1));
                _allocator.construct(_array + _size, val);
                _size++;
            }
            void pop_back()
            {
                if (!this->empty())
                {
                    _allocator.destroy(_array + _size - 1);
                    _size--;
                }
            }
            iterator insert(iterator position, const value_type& val)
            {
                difference_type pos = ft::distance(this->begin(), position);

                if (_capacity == _size)
                    this->_reserve(this->_findAllocSize(_size + 1));
                
                position = this->begin() + pos;
                this->_shiftRight(position, 1);
                *position = val;

                _size++;

                return iterator(_array + pos);
            }
            void insert(iterator position, size_type n, const value_type& val)
            {
                if (n > this->max_size() - _size)
                    throw std::length_error("vector");

                difference_type pos = ft::distance(this->begin(), position);

                if (_capacity - _size < n)
                    this->_reserve(this->_findAllocSize(_size + n));

                position = this->begin() + pos;
                this->_shiftRight(position, n);
                for (size_type i = 0; i < n; ++i)
                    *(position + i) = val;

                _size += n;
            }
            template <class InputIterator>
            void insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
            {
                size_type       n = ft::distance(first, last);
                difference_type pos = ft::distance(this->begin(), position);

                if (_capacity - _size < n)
                    this->_reserve(this->_findAllocSize(_size + n));

                position = this->begin() + pos;
                this->_shiftRight(position, n);
                while (first != last)
                {
                    *position = *first;
                    ++position;
                    ++first;
                }
                
                _size += n;
            }
            iterator erase(iterator position)
            {
                this->_destroy(position);
                this->_shiftLeft(position, 1);
                _size--;
                return position;
            }
            iterator erase(iterator first, iterator last)
            {
                difference_type n = ft::distance(first, last);
                this->_destroy(first, last);
                this->_shiftLeft(first, n);
                _size -= n;
                return first;
            }
            void swap(vector& x)
            {
                this->_swap(_array, x._array);
                this->_swap(_capacity, x._capacity);
                this->_swap(_size, x._size);
            }
            void clear()
            {
                this->_destroy(this->begin(), this->end());
                _size = 0;
            }

            // Allocator
            allocator_type get_allocator() const
            {
                return _allocator;
            }
    };
    // Non-member function overloads
    template <typename T, typename Alloc>
    bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    template <typename T, typename Alloc>
    bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <typename T, typename Alloc>
    bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <typename T, typename Alloc>
    bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (lhs == rhs) || (lhs < rhs);
    }
    template <typename T, typename Alloc>
    bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return !(lhs <= rhs);
    }
    template <typename T, typename Alloc>
    bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (lhs == rhs) || (lhs > rhs);
    }
    template <typename T, typename Alloc> 
    void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)
    {
        lhs.swap(rhs);
    }
}

#endif