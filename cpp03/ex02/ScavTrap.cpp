#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap parameterized constructor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ScavTrap Copy constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ScavTrap Copy assignment" << std::endl;
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is in Gate keeper mode" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if (_tryPerformAction())
	{
		std::cout <<  "ScavTrap " <<  _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		return ;
	}
}
