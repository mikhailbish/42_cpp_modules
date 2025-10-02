#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "DiamondTrap default constructor" << std::endl;
	_hitPoints = FragTrap::initialHP;
	_energyPoints = ScavTrap::initialEP;
	_attackDamage = FragTrap::initialAD;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap parameterized constructor" << std::endl;
	_name = name;
	_hitPoints = FragTrap::initialHP;
	_energyPoints = ScavTrap::initialEP;
	_attackDamage = FragTrap::initialAD;
}

DiamondTrap::DiamondTrap(DiamondTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap Copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap Copy assignment" << std::endl;
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);	
}

void DiamondTrap::whoAmI()
{
	std::cout << _name << " is questioning it's existense." << std::endl;
}
