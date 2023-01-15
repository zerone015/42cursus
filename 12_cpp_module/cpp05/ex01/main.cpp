#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat  ba("ba", 150);
    Form        fa("fa", 50, 50);

    std::cout << fa << std::endl;

    ba.signForm(fa);
    std::cout << fa << std::endl;

    while (ba.getGrade() != 50)
        ba.increaseGrade();
    ba.signForm(fa);
    std::cout << fa << std::endl;

    Form    abnormal("abnormal", 151, 150);

    Form    test1("test1", 10, 10);
    Form    test2("test2", 42, 42);

    test1 = test2;
    std::cout << test1 << std::endl;

    Form    test3(test2);
    std::cout << test3 << std::endl;
    
    return 0;
}