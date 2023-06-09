#include "Data.hpp"

uintptr_t   serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data    *deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main()
{
    Data    *data = new Data("son", 21);

    std::cout << *data;

    uintptr_t   addr = serialize(data);
    data = deserialize(addr);

    std::cout << *data;
    
    delete data;
    return 0;
}