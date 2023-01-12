#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain   *brain;
    public:
        void    makeSound() const;
        Brain   *getBrain();
        Dog();
        Dog(const Dog &src);
        Dog& operator=(const Dog &src);
        ~Dog();
};

#endif