#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef>
# include <iterator>

namespace ft
{
    template <typename T>
    class random_access_iterator
    {
        public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef T                               value_type;
			typedef std::ptrdiff_t                  difference_type;
			typedef T*                              pointer;
			typedef T&                              reference;
        protected:
            pointer _cur;
        public:
            random_access_iterator() : _cur(NULL) {}
            random_access_iterator(pointer p) : _cur(p) {}
            random_access_iterator(const random_access_iterator<value_type>& src) : _cur(src._cur) {}
			operator random_access_iterator<const value_type>() const 
			{
				return random_access_iterator<const value_type>(_cur);
			}
            random_access_iterator<value_type>& operator=(const random_access_iterator<value_type>& src)
            {
                _cur = src._cur;
                return *this;
            }
            ~random_access_iterator() {}
            pointer base() const
            {
                return _cur;
            }
            reference operator*() const
            {
			    return *_cur;
			}
		    pointer operator->() const 
            {
			    return _cur;
		    }
            random_access_iterator& operator++() 
            {
			    ++_cur;
			    return *this;
            }
		    random_access_iterator& operator--()
            {
			    --_cur;
			    return *this;
		    }
		    random_access_iterator operator++(int)
            {
			    random_access_iterator tmp(*this);
                ++_cur;
			    return tmp;
		    }
		    random_access_iterator operator--(int) 
            {
			    random_access_iterator tmp(*this);
			    --_cur;
			    return tmp;
		    }
            random_access_iterator operator+(difference_type n) const 
            {
			    return random_access_iterator(_cur + n);
		    }
            random_access_iterator operator-(difference_type n) const 
            {
			    return random_access_iterator(_cur - n);
		    }
            random_access_iterator& operator+=(difference_type n) 
            {
			    _cur += n;
			    return *this;
		    }
		    random_access_iterator& operator-=(difference_type n)
            {
			    _cur -= n;
			    return *this;
		    }
            reference operator[](difference_type n) const 
            {
			    return _cur[n];
		    }
    };
    template <typename T1, typename T2>
	bool operator==(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
    {
		return lhs.base() == rhs.base();
	}
	template <typename T1, typename T2>
	bool operator!=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
    {
		return lhs.base() != rhs.base();
	}
	template <typename T1, typename T2>
	bool operator<(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
    {
		return lhs.base() < rhs.base();
	}
	template <typename T1, typename T2>
	bool operator>(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
    {
		return lhs.base() > rhs.base();
	}
	template <typename T1, typename T2>
	bool operator<=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
    {
		return lhs.base() <= rhs.base();
	}
	template <typename T1, typename T2>
	bool operator>=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
    {
		return lhs.base() >= rhs.base();
	}
    template <typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& it)
    {
		return it + n;
    }
    template <typename T1, typename T2>
	typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
    {
		return lhs.base() - rhs.base();
    }
}

#endif