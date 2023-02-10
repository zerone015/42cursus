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

    template <
        typename Category,
        typename T,
        typename Distance = std::ptrdiff_t,
        typename Pointer = T*,
        typename Reference = T&> 
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
        protected:
            pointer _ptr;
        public:
            random_access_iterator() : _ptr(NULL) {}
            random_access_iterator(pointer p) : _ptr(p) {}
            random_access_iterator(const random_access_iterator<T>& src) : _ptr(src._ptr) {}
            random_access_iterator<T>& operator=(const random_access_iterator<T>& src)
            {
                _ptr = src._ptr;
                return *this;
            }
            virtual ~Random_access_iterator() {}
            pointer base() const
            {
                return _ptr;
            }
            reference operator*() const
            {
			    return *_ptr;
			}
		    pointer operator->() const 
            {
			    return _ptr;
		    }
            random_access_iterator& operator++() 
            {
			    ++_ptr;
			    return *this;
            }
		    random_access_iterator& operator--()
            {
			    --_ptr;
			    return *this;
		    }
		    random_access_iterator operator++(int)
            {
			    random_access_iterator tmp(*this);
                ++_ptr;
			    return tmp;
		    }
		    random_access_iterator operator--(int) 
            {
			    random_access_iterator tmp(*this);
			    --_ptr;
			    return tmp;
		    }
            random_access_iterator operator+(difference_type n) const 
            {
			    return random_access_iterator(_ptr + n);
		    }
            random_access_iterator operator-(difference_type n) const 
            {
			    return random_access_iterator(_ptr - n);
		    }
            random_access_iterator& operator+=(difference_type n) 
            {
			    _ptr += n;
			    return *this;
		    }
		    random_access_iterator& operator-=(difference_type n)
            {
			    _ptr -= n;
			    return *this;
		    }
            reference operator[](difference_type n) const 
            {
			    return _ptr[n];
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