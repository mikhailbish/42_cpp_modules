#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <limits>

class ClapTrap {
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		bool _tryPerformAction(void);

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& other);
		ClapTrap& operator=(const ClapTrap &other);
		virtual ~ClapTrap();
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void);
		unsigned int getEnergy(void);
		unsigned int getAttackDamage(void);
};

#endif
