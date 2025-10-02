#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_hitPoints = ClapTrap::_startHP;
	_energyPoints = ClapTrap::_startEP;
	_attackDamage = ClapTrap::_startAD;
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = ClapTrap::_startHP;
	_energyPoints = ClapTrap::_startEP;
	_attackDamage = ClapTrap::_startAD;
	std::cout << "ClapTrap parameterized constructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap Copy constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

bool ClapTrap::_tryPerformAction(void)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " doesn't have hitpoints to perform an action" << std::endl;
		return false;
	}
	if (_energyPoints)
	{
		_energyPoints -= 1;
		return (true);
	}
	std::cout << "ClapTrap " << _name << " doesn't have energy to perform an action" << std::endl;
	return (false);
}

void ClapTrap::attack(const std::string& target)
{
	if (_tryPerformAction())
	{
		std::cout <<  "ClapTrap " <<  _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		return ;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < _hitPoints )
	{
		_hitPoints -= amount;
		std::cout <<  "ClapTrap " <<  _name << " loses " << amount << " hitpoints" << std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout <<  "ClapTrap " <<  _name << " loses all its hitpoints!" << std::endl;
	}
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_tryPerformAction())
	{
		if (std::numeric_limits<unsigned int>::max() - amount < _hitPoints)
		{
			std::cout <<  "ClapTrap " <<  _name << " has full health" << std::endl;
			_hitPoints = std::numeric_limits<unsigned int>::max();
		}
		else
		{
			std::cout <<  "ClapTrap " <<  _name << " repairs itself for " << amount << "hp." << std::endl;
			_hitPoints += amount;
		}
		return ;
	}
}

unsigned int ClapTrap::getHitPoints(void)
{
	return (_hitPoints);
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
