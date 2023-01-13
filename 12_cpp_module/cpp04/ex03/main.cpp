#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);

    Character* son = new Character("son");
    tmp = src->createMateria("ice");
    son->equip(tmp);
    tmp = src->createMateria("cure");
    son->equip(tmp);

    tmp = son->getInventory(0);
    son->unequip(0);

    delete bob;
    delete me;
    delete src;
    delete tmp;
    delete son;
    
    return 0;
}