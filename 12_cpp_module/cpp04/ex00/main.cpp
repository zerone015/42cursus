#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    cat->makeSound();
    dog->makeSound();
    animal->makeSound();
    wrongCat->makeSound();

    delete  animal;
    delete  dog;
    delete  cat;
    delete  wrongCat;

    return 0;
}