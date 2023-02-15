#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include "iterator_tag.hpp"
# include "iterator_traits.hpp"

namespace ft
{
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