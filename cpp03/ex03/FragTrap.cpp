#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	_hitPoints = initialHP;
	_energyPoints = initialEP;
	_attackDamage = initialAD;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap parameterized constructor" << std::endl;
	_hitPoints = initialHP;
	_energyPoints = initialEP;
	_attackDamage = initialAD;
}

FragTrap::FragTrap(FragTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "FragTrap Copy constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "FragTrap Copy assignment" << std::endl;
	return (*this);
}

void FragTrap::guardGate()
{
	std::cout << "ScavTrap is in Gate keeper mode" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_tryPerformAction())
	{
		std::cout <<  "ScavTrap " <<  _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		return ;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout <<  "FragTrap " <<  _name << " highfives everybody" << std::endl;
	
}
