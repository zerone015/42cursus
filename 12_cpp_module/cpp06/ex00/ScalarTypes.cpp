#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cfloat>
#include <climits>
#include <math.h>
#include "ScalarTypes.hpp"

ScalarTypes::ScalarTypes() {}

ScalarTypes::ScalarTypes(std::string str) : _str(str) {}

ScalarTypes::ScalarTypes(const ScalarTypes &src) : _str(src._str), _float(src._float), _double(src._double) {}

ScalarTypes&    ScalarTypes::operator=(const ScalarTypes &src)
{
    this->_str = src._str;
    this->_float = src._float;
    this->_double = src._double;

    return *this;
}

ScalarTypes::~ScalarTypes() {}

bool    ScalarTypes::isFractionZero(const std::string &str) const
{
    size_t  idx = 0;

    try
    {
        while (str.at(idx) == ' ' || (str.at(idx) >= 9 && str.at(idx) <= 13))
            idx++;
        if (str.at(idx) == '-' || str.at(idx) == '+')
            idx++;
        while (std::isdigit(str.at(idx)))
            idx++;
        if (str.at(idx) == '.')
        {
            while (str.at(++idx) == '0')
                ;
            if (std::isdigit(str.at(idx)))
                return false;
        }
    }
    catch(std::exception &){}
    return true;
}

void    ScalarTypes::convertChar() const
{
    if (isnan(this->_double) 
        || isinf(this->_double)
	    || this->_double < 0 
        || this->_double > 127)
    {
		std::cout << "char: impossible" << std::endl;
        return ;
    }
	if (!std::isprint(this->_double))
    {
		std::cout << "char: Non displayable" << std::endl;
        return ;
    }
	std::cout << "char: '" << static_cast<char>(this->_double) << "'" << std::endl;
}

void    ScalarTypes::convertInt() const
{
    if (isnan(this->_double)
		|| isinf(this->_double)
		|| this->_double > INT_MAX
		|| this->_double < INT_MIN)
    {
		std::cout << "int: impossible" << std::endl;
        return ;
    }
    std::cout << "int: " << static_cast<int>(this->_double) << std::endl;
}

void    ScalarTypes::convertFloat()
{
    if (!isinf(this->_double) 
        && (FLT_MAX < this->_double
        || -FLT_MAX > this->_double))
    {
		std::cout << "float: impossible" << std::endl;
        return ;
    }
    this->_float = static_cast<float>(this->_double);
	std::cout << "float: " << this->_float;
    if (!isnan(this->_float)
        && !isinf(this->_float)
        && (this->_str.find('.') == std::string::npos
        || isFractionZero(this->_str)))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}
 
void    ScalarTypes::convertDouble() const
{
    std::cout << "double: " << this->_double;
    if (!isnan(this->_double) 
        && !isinf(this->_double)
        && (this->_str.find('.') == std::string::npos
        || isFractionZero(this->_str)))
		std::cout << ".0";
	std::cout << std::endl;
}

void    ScalarTypes::convert()
{
    this->_double = std::atof(this->_str.c_str());
    convertChar();
    convertInt();
    convertFloat();
    convertDouble();
}