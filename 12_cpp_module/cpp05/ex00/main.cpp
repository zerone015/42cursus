#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat  abnormal1("abnormal1", 150);
    Bureaucrat  abnormal2("abnormal2", 1);

    abnormal1.decreaseGrade();
    abnormal2.increaseGrade();

    Bureaucrat  abnormal3("abnormal3", 5);
    abnormal3.setGrade(-1);

    Bureaucrat  normal("normal", 20);
    normal.increaseGrade();

    std::cout << abnormal1 << "\n";
    std::cout << abnormal2 << "\n";
    std::cout << abnormal3 << "\n";
    std::cout << normal << std::endl;

    Bureaucrat test1("test1", 1);
    Bureaucrat test2("test2", 100);

    test2 = test1;
    std::cout << test2 << std::endl;

    return 0;
}