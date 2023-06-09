#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
    public:
        void    makeSound() const;
        Dog();
        Dog(const Dog &src);
        Dog& operator=(const Dog &src);
        ~Dog();
};

#endif