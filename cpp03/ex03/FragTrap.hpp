#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		static const unsigned int initialHP = 100;
		static const unsigned int initialEP = 100;
		static const unsigned int initialAD = 30;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &other);
		FragTrap& operator=(const FragTrap &other);
		~FragTrap();
		void attack(const std::string& target) override;
		void guardGate();
		void highFivesGuys();
};

#endif
