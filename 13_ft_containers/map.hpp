#ifndef MAP_HPP
# define MAP_HPP

# include <functional>

namespace ft
{

template <
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> > > 
class map
{

}

}

#endif