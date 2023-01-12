#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        void    makeSound() const;
        WrongCat();
        WrongCat(const WrongCat &src);
        WrongCat& operator=(const WrongCat &src);
        ~WrongCat();
};

#endif