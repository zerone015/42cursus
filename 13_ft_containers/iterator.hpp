#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag, output_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <typename _Iter>
    struct iterator_traits
    {
        typedef typename _Iter::iterator_category   iterator_category;
        typedef typename _Iter::value_type          value_type;
        typedef typename _Iter::difference_type     difference_type;
        typedef typename _Iter::pointer             pointer;
        typedef typename _Iter::reference           reference;
    };

    template <typename T>
    struct iterator_traits<T*>
    {
        typedef random_access_iterator_tag  iterator_category;
        typedef T                           value_type;
        typedef ptrdiff_t                   difference_type;
        typedef T*                          pointer;
        typedef T&                          reference;
    };

    template <typename T>
    struct iterator_traits<const T*>
    {
        typedef random_access_iterator_tag  iterator_category;
        typedef T                           value_type;
        typedef ptrdiff_t                   difference_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
    };

    template <typename Iter>
    class reverse_iterator
    {
        protected:
            Iter   _base;
        public:
            typedef Iter                                               iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category  iterator_category;
            typedef typename iterator_traits<Iter>::value_type         value_type;
            typedef typename iterator_traits<Iter>::difference_type    difference_type;
            typedef typename iterator_traits<Iter>::pointer            pointer;
            typedef typename iterator_traits<Iter>::reference          reference;

            reverse_iterator() {}
            explicit reverse_iterator(iterator_type it) : _base(it) {}
            template <typename U>
            reverse_iterator(const reverse_iterator<U>& src) : _base(src.base()) {}
            template <typename V>
            reverse_iterator& operator=(const reverse_iterator<V>& src)
            {
                _base = src.base();
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
                --_base;
                return *this;
            }
            reverse_iterator& operator--()
            {
                ++_base;
                return *this;
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp(*this);
                --_base;
                return tmp;
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp(*this);
                ++_base;
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
                _base -= n;
                return *this;
            }
            reverse_iterator& operator-=(difference_type n)
            {
                _base += n;
                return *this;
            }
            iterator_type base() const 
            {
                return _base;
            }
    };
    
    template <typename Iterator1, typename Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() == rhs.base());
	}
	template <typename Iterator1, typename Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() != rhs.base());
	}
	template <typename Iterator1, typename Iterator2>
	bool operator< (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() > rhs.base());
	}
	template <typename Iterator1, typename Iterator2>
	bool operator> (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() < rhs.base());
	}
	template <typename Iterator1, typename Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() >= rhs.base());
	}
	template <typename Iterator1, typename Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() <= rhs.base());
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