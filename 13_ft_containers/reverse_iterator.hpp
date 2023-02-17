#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
    template <typename Iter>
    class reverse_iterator
    {
        protected:
            Iter   _cur;
        public:
            typedef Iter                                                    iterator_type;
            typedef typename ft::iterator_traits<Iter>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<Iter>::value_type          value_type;
            typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer             pointer;
            typedef typename ft::iterator_traits<Iter>::reference           reference;

            reverse_iterator() : _cur(iterator_type()) {}
            explicit reverse_iterator(iterator_type it) : _cur(it) {}
            template <typename U>
            reverse_iterator(const reverse_iterator<U>& src) : _cur(src.base()) {}
            template <typename V>
            reverse_iterator& operator=(const reverse_iterator<V>& src)
            {
                _cur = src.base();
                return *this;
            }
            reference operator*() const
            {
                iterator_type tmp(this->base());
                return *--tmp;
            }
            pointer operator->() const
            {
                return &(operator*());
            }
            reference operator[](difference_type n) const
            {
                return base()[-n - 1];
            }
            reverse_iterator& operator++()
            {
                --_cur;
                return *this;
            }
            reverse_iterator& operator--()
            {
                ++_cur;
                return *this;
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp(*this);
                --_cur;
                return tmp;
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp(*this);
                ++_cur;
                return tmp;
            }
            reverse_iterator operator+(difference_type n) const
            {
                return reverse_iterator(this->base() - n);
            }
            reverse_iterator operator-(difference_type n) const
            {
                return reverse_iterator(this->base() + n);
            }
            reverse_iterator& operator+=(difference_type n)
            {
                _cur -= n;
                return *this;
            }
            reverse_iterator& operator-=(difference_type n)
            {
                _cur += n;
                return *this;
            }
            iterator_type base() const 
            {
                return _cur;
            }
    };
    template <typename Iterator1, typename Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
		return lhs.base() == rhs.base();
	}
    template <typename Iterator1, typename Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
		return lhs.base() != rhs.base();
	}
    template <typename Iterator1, typename Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
		return lhs.base() > rhs.base();
	}
    template <typename Iterator1, typename Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
		return lhs.base() < rhs.base();
	}
    template <typename Iterator1, typename Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
		return lhs.base() >= rhs.base();
	}
    template <typename Iterator1, typename Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
		return lhs.base() <= rhs.base();
    }
    template <typename Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
    {
        return it + n;
    }
    template <typename Iterator1, typename Iterator2>
    typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return rhs.base() - lhs.base();
    }
}

#endif