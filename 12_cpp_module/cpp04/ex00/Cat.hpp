#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
    public:
        void    makeSound() const;
        Cat();
        Cat(const Cat &src);
        Cat& operator=(const Cat &src);
        ~Cat();
};

#endif