#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "iterator.hpp"
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
        void reserve_loop(size_type n)
        {
            if (n > this->max_size() - _size)
                throw std::length_error("vector");
            while (n > (_capacity - _size))
                this->reserve(_capacity * 2);
        }
        void shift_left(iterator position, size_type n)
        {
            for (iterator it = position; it != this->end() - n; it++)
                *it = *(it + n);
        }
        void shift_right(iterator position, size_type n)
        {
            for (iterator it = this->end() - 1; it >= position; it--)
                *(it + n) = *it;
        }
        void allocator_destroy(iterator position)
        {
            _allocator.destroy(&(*position));
        }
        void allocator_destroy(iterator first, iterator last)
        {
            while (first != last)
            {
                _allocator.destroy(&(*first));
                first++;
            }
        }
        template <typename Type>
        void	swap(Type &a, Type &b)
        {
            Type tmp;

            tmp = a;
            a = b;
            b = tmp;
        }
    public:
        // default constructor
        explicit vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _array(NULL), _capacity(0), _size(0) {}
        // fill constructor
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _capacity(n), _size(n)
        {
            _array = _allocator.allocate(_capacity);
            for (size_type i = 0; i < n; i++)
                _allocator.construct(_array + i, val);
        }
        // range constructor
        template <typename InputIterator>
        vector(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()) : _allocator(alloc)
        {
            _capacity = ft::distance(first, last);
            _array = _allocator.allocate(_capacity);
            _size = 0;
            this->insert(this->end(), first, last);
        }
        // copy constructor
        vector(const vector& src) : _allocator(allocator_type(src.get_allocator()))
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
            _allocator.deallocate(_array, _capacity);
            _size = 0;
            _capacity = src.capacity();
            _array = _allocator.allocate(_capacity);
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
                if (n > this->max_size())
                    throw std::length_error("vector");
                this->insert(this->end(), n - _size, val);
            }
            else if (n < _size)
            {
                for (size_type i = n; i < _size; i++)
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
            {
                pointer new_array = _allocator.allocate(n);
                for (size_type i = 0; i < _size; i++)
                    _allocator.construct(new_array + i, *(_array + i));
                for (size_type i = 0; i < _size; i++)
				    _allocator.destroy(_array + i);
                _allocator.deallocate(_array, _capacity);
                _capacity = n;
                _array = new_array;
            }
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
        void assign(InputIterator first, InputIterator last)
        {
            this->clear();
            for (; first != last; first++)
                this->push_back(*first);
        }
        void assign(size_type n, const value_type& val)
        {
            this->clear();
            while (n--)
                this->push_back(val);
        }
        void push_back(const value_type& val)
        {
            if (_size == _capacity)
                _capacity == 0 ? this->reserve(1) : this->reserve(_capacity * 2);
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
            this->insert(position, 1, val);
            return iterator(_array + pos);
        }
        void insert(iterator position, size_type n, const value_type& val)
        {
            difference_type pos = ft::distance(this->begin(), position);
            this->reserve_loop(n);
            position = this->begin() + pos;
            this->shift_right(position, n);
            for (size_type i = 0; i < n; i++)
                *(position + i) = val;
            _size += n;
        }
        template <class InputIterator>
        void insert(iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
        {
            difference_type pos = ft::distance(this->begin(), position);
            this->reserve_loop(ft::distance(first, last));
            position = this->begin() + pos;
            size_type n = ft::distance(first, last);
            this->shift_right(position, n);
            while (first != last)
            {
                *position = *first;
                position++;
                first++;
            }
            _size += n;
        }
        iterator erase(iterator position)
        {
            this->allocator_destroy(position);
            this->shift_left(position, 1);
            _size--;
            return position;
        }
        iterator erase(iterator first, iterator last)
        {
            difference_type n = ft::distance(first, last);
            this->allocator_destroy(first, last);
            this->shift_left(first, n);
            _size -= n;
            return first;
        }
        void swap(vector& x)
        {
            this->swap(_array, x._array);
            this->swap(_allocator, x._allocator);
            this->swap(_capacity, x._capacity);
            this->swap(_size, x._size);
        }
        void clear()
        {
            this->allocator_destroy(this->begin(), this->end());
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
        return !(rhs < lhs);
    }
    template <typename T, typename Alloc>
    bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return rhs < lhs;
    }
    template <typename T, typename Alloc>
    bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return !(lhs < rhs);
    }
    template <typename T, typename Alloc> 
    void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
    {
        x.swap(y);
    }
}

#endif