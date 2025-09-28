#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

bool ClapTrap::_trySpendEnergy(void)
{
	if (this->_energyPoints)
	{
		this->_energyPoints -= 1;
		return (true);
	}
	return (false);
}

void ClapTrap::attack(const std::string& target)
{
	if (_trySpendEnergy())
	{
		std::cout <<  "ClapTrap " <<  _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		return ;
	}
	std::cout <<  "ClapTrap " <<  _name << " doesn't have energy to attack " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < _hitPoints )
		_hitPoints -= amount;
	else
		_hitPoints = 0;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_trySpendEnergy())
	{
		std::cout <<  "ClapTrap " <<  _name << " repairs itself for " << amount << "hp." << std::endl;
		return ;
	}
	std::cout <<  "ClapTrap " <<  _name << " doesn't have energy to repair itself" << std::endl;
}

unsigned int ClapTrap::getEnergy(void)
{
	return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void)
{
	return (_attackDamage);
}

std::string ClapTrap::getName()
{
	return (_name);
}
