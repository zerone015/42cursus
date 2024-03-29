#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include "integral_constant.hpp"

namespace ft
{
    template <typename T> 
    struct is_integral : public integral_constant<bool, false> {};

    template<> struct is_integral<bool> : true_type {};
	template<> struct is_integral<char> : true_type {};
	template<> struct is_integral<wchar_t> : true_type {};
	template<> struct is_integral<signed char> : true_type {};
	template<> struct is_integral<short> : true_type {};
	template<> struct is_integral<int> : true_type {};
	template<> struct is_integral<long> : true_type {};
	template<> struct is_integral<long long> : true_type {};
	template<> struct is_integral<unsigned char> : true_type {};
	template<> struct is_integral<unsigned short> : true_type {};
	template<> struct is_integral<unsigned int> : true_type {};
	template<> struct is_integral<unsigned long> : true_type {};
	template<> struct is_integral<unsigned long long> : true_type {};

    template<> struct is_integral<const bool> : true_type {};
	template<> struct is_integral<const char> : true_type {};
	template<> struct is_integral<const wchar_t> : true_type {};
	template<> struct is_integral<const signed char> : true_type {};
	template<> struct is_integral<const short> : true_type {};
	template<> struct is_integral<const int> : true_type {};
	template<> struct is_integral<const long> : true_type {};
	template<> struct is_integral<const long long> : true_type {};
	template<> struct is_integral<const unsigned char> : true_type {};
	template<> struct is_integral<const unsigned short> : true_type {};
	template<> struct is_integral<const unsigned int> : true_type {};
	template<> struct is_integral<const unsigned long> : true_type {};
	template<> struct is_integral<const unsigned long long> : true_type {};

    template<> struct is_integral<volatile bool> : true_type {};
	template<> struct is_integral<volatile char> : true_type {};
	template<> struct is_integral<volatile wchar_t> : true_type {};
	template<> struct is_integral<volatile signed char> : true_type {};
	template<> struct is_integral<volatile short> : true_type {};
	template<> struct is_integral<volatile int> : true_type {};
	template<> struct is_integral<volatile long> : true_type {};
	template<> struct is_integral<volatile long long> : true_type {};
	template<> struct is_integral<volatile unsigned char> : true_type {};
	template<> struct is_integral<volatile unsigned short> : true_type {};
	template<> struct is_integral<volatile unsigned int> : true_type {};
	template<> struct is_integral<volatile unsigned long> : true_type {};
	template<> struct is_integral<volatile unsigned long long> : true_type {};

    template<> struct is_integral<const volatile bool> : true_type {};
	template<> struct is_integral<const volatile char> : true_type {};
	template<> struct is_integral<const volatile wchar_t> : true_type {};
	template<> struct is_integral<const volatile signed char> : true_type {};
	template<> struct is_integral<const volatile short> : true_type {};
	template<> struct is_integral<const volatile int> : true_type {};
	template<> struct is_integral<const volatile long> : true_type {};
	template<> struct is_integral<const volatile long long> : true_type {};
	template<> struct is_integral<const volatile unsigned char> : true_type {};
	template<> struct is_integral<const volatile unsigned short> : true_type {};
	template<> struct is_integral<const volatile unsigned int> : true_type {};
	template<> struct is_integral<const volatile unsigned long> : true_type {};
	template<> struct is_integral<const volatile unsigned long long> : true_type {};
}

#endif