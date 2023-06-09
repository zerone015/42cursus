#ifndef SCALAR_TYPES_HPP
# define SCALAR_TYPES_HPP

# include <string>

class ScalarTypes
{
    private:
        std::string _str;
        float       _float;
        double      _double;
        void        convertChar() const;
        void        convertInt() const;
        void        convertFloat();
        void        convertDouble() const;
        bool        isFractionZero(const std::string &str) const;
    public:
        ScalarTypes();
        ScalarTypes(std::string str);
        ScalarTypes(const ScalarTypes &src);
        ScalarTypes&    operator=(const ScalarTypes &src);
        ~ScalarTypes();
        void            convert();
};

#endif