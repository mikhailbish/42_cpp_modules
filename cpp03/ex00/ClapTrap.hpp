#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <string>
#include <iostream>
#include <limits>

class ClapTrap {
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		bool _tryPerformAction(void);

		static const unsigned int _startHP = 10;
		static const unsigned int _startEP = 10;
		static const unsigned int _startAD = 0;
		
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& other);
		ClapTrap& operator=(const ClapTrap &other);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void);
		unsigned int getEnergy(void);
		unsigned int getAttackDamage(void);
		unsigned int getHitPoints(void);
};

#endif
