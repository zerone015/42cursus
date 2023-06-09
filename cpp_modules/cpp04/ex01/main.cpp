#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* arr[4] = {new Dog, new Dog, new Cat, new Cat};
    
    Dog* l = new Dog();
    Dog* k = new Dog(*l);

    for (int i = 0; i < 100; i++)
        k->getBrain()->setIdea(i, "two");
    for (int i = 0; i < 100; i++)
        std::cout << l->getBrain()->getIdea(i) << std::endl;
    for (int i = 0; i < 100; i++)
        std::cout << k->getBrain()->getIdea(i) << std::endl;

    for (int i = 0; i < 4; i++)
        delete arr[i];
    delete l;
    delete k;

    return 0;
}