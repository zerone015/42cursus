#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;
    public:
	    void	whoAmI(void);
		void    showStatus(void);
        DiamondTrap(void);
	    DiamondTrap(std::string name);
	    DiamondTrap(const DiamondTrap& obj);
	    DiamondTrap& operator=(const DiamondTrap& obj);
	    ~DiamondTrap(void);
};

#endif