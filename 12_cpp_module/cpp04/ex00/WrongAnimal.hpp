#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        void    makeSound() const;
        std::string     getType() const;
        WrongAnimal();
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal& operator=(const WrongAnimal &src);
        ~WrongAnimal();
};

#endif