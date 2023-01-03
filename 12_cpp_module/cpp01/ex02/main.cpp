#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "string memory address: " << &string << "\n";
    std::cout << "stringPTR memory address: " << stringPTR << "\n";
    std::cout << "stringREF memory address: " << &stringREF << "\n";

    std::cout << "string value: " << string << "\n";
    std::cout << "stringPTR value: " << *stringPTR << "\n";
    std::cout << "stringREF value: " << stringREF << std::endl;
    return (0);
}