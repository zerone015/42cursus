#include "Data.hpp"

Data::Data() {}

Data::Data(std::string name, int value) : name(name), value(value) {}

Data::Data(const Data &src) : name(src.name), value(src.value) {}

Data&   Data::operator=(const Data &src)
{
    this->name = src.name;
    this->value = src.value;
    return *this;
}

Data::~Data() {}

const std::string&  Data::getName() const
{
    return this->name;
}

int Data::getValue() const
{
    return this->value;
}

std::ostream&   operator<<(std::ostream& outputStream, const Data& obj)
{
    std::cout << "name: " << obj.getName() << std::endl;
    std::cout << "value: " << obj.getValue() << std::endl;
	return outputStream;
}