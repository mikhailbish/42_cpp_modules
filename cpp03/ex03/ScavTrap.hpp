#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		static const unsigned int initialHP = 100;
		static const unsigned int initialEP = 50;
		static const unsigned int initialAD = 20;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target) override;
};

#endif
