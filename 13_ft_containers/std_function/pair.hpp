#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
    template <typename T1, typename T2>
    struct pair
    {
        typedef T1  first_type;
        typedef T2  second_type;

        first_type  first;
        second_type second;

        pair() : first(first_type()), second(second_type()) {}
        template <typename U, typename V>
        pair(const pair<U, V>& src) : first(src.first), second(src.second) {}
        pair(const first_type& a, const second_type& b) : first(a), second(b) {}

        pair& operator=(const pair& src)
        {
            if (this == &src)
                return *this;
            first = src.first;
            second = src.second;
            return *this;
        }
    };

    template <typename T1, typename T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return ft::pair<T1, T2>(x, y);
    }
    
    template <typename T1, typename T2>
    bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
    template <typename T1, typename T2>
    bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return !(lhs == rhs);
    }
    template <typename T1, typename T2>
    bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }
    template <typename T1, typename T2>
    bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return !(rhs < lhs);
    }
    template <typename T1, typename T2>
    bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return rhs < lhs;
    }
    template <typename T1, typename T2>
    bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
    {
        return !(lhs < rhs);
    }
}

#endif