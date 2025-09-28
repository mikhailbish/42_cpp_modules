#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	std::cout << "DiamondTrap parameterized constructor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
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
	if (_trySpendEnergy())
	{
		std::cout <<  "ScavTrap " <<  _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		return ;
	}
	std::cout <<  "ScavTrap " <<  _name << " doesn't have energy to attack " << target << std::endl;
}

void DiamondTrap::whoAmI()
{

}
