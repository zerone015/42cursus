#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag, public output_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&> 
    struct iterator
    {
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };

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
        typedef std::ptrdiff_t              difference_type;
        typedef T*                          pointer;
        typedef T&                          reference;
    };

    template <typename T>
    struct iterator_traits<const T*>
    {
        typedef random_access_iterator_tag  iterator_category;
        typedef T                           value_type;
        typedef std::ptrdiff_t              difference_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
    };

    template <typename Iter>
    class reverse_iterator
    {
        protected:
            Iter   _cur;
        public:
            typedef Iter                                               iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category  iterator_category;
            typedef typename iterator_traits<Iter>::value_type         value_type;
            typedef typename iterator_traits<Iter>::difference_type    difference_type;
            typedef typename iterator_traits<Iter>::pointer            pointer;
            typedef typename iterator_traits<Iter>::reference          reference;

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

    template <typename T>
    class random_access_iterator : public iterator<random_access_iterator_tag, T>
    {
        public:
			typedef typename iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
			typedef typename iterator<random_access_iterator_tag, T>::value_type        value_type;
			typedef typename iterator<random_access_iterator_tag, T>::difference_type   difference_type;
			typedef typename iterator<random_access_iterator_tag, T>::pointer           pointer;
			typedef typename iterator<random_access_iterator_tag, T>::reference         reference;
        protected:
            pointer _cur;
        public:
            random_access_iterator() : _cur(NULL) {}
            random_access_iterator(pointer p) : _cur(p) {}
            random_access_iterator(const random_access_iterator<T>& src) : _cur(src._cur) {}
            random_access_iterator<T>& operator=(const random_access_iterator<T>& src)
            {
                _cur = src._cur;
                return *this;
            }
            virtual ~random_access_iterator() {}
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

    template <typename InputIt>
	typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last)
    {
		typename ft::iterator_traits<InputIt>::difference_type ret = 0;
        for (; first != last; first++)
            ret++;
		return ret;
	}
}

#endif