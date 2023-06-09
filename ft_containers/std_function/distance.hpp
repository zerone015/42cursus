#ifndef DISTANCE_HPP
# define DISTANCE_HPP

# include "../iterator/iterator_traits.hpp"

namespace ft
{
    template <typename InputIt>
	typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last)
    {
		typename ft::iterator_traits<InputIt>::difference_type ret = 0;
        for (; first != last; ++first)
            ++ret;
		return ret;
	}
}

#endif