#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
    private:
        std::string name;
        int         value;
    public:
        Data();
        Data(std::string name, int value);
        Data(const Data &src);
        Data&   operator=(const Data &src);
        ~Data();
        const std::string&  getName() const;
        int                 getValue() const;
};

std::ostream&   operator<<(std::ostream& outputStream, const Data& obj);

#endif