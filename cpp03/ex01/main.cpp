#include "ScavTrap.hpp"

void attackUntilNoEnergy(ScavTrap &first, ScavTrap &second)
{
	if (!first.getHitPoints())
		return ;
	while (first.getEnergy())
	{
		first.attack(second.getName());
		second.takeDamage(first.getAttackDamage());
	}
	first.attack(second.getName());
}

void repairUntilNoEnergy(ScavTrap &first)
{
	if (!first.getHitPoints())
		return ;
	while (first.getEnergy())
	{
		first.beRepaired(10);
	}
	first.beRepaired(10);
}

int main()
{
	ClapTrap *wow;
	ClapTrap clapSome("meow");
	ScavTrap scav1("yo");
	ScavTrap scav2("wow");
	ScavTrap *scav3 = new (std::nothrow)ScavTrap("HeapScav");
	if (scav3 == nullptr)
		return 1;
	wow = &scav1;
	std::cout << "---------------------------------------------------------------"<< std::endl;
	wow->ClapTrap::attack("Base");
	scav1.ClapTrap::attack("Base");
	std::cout << "---------------------------------------------------------------"<< std::endl;
	wow->attack("Base");
	scav1.attack("Base");
	std::cout << "---------------------------------------------------------------"<< std::endl;
	clapSome.attack("test");
	std::cout << "---------------------------------------------------------------"<< std::endl;
	attackUntilNoEnergy(scav1, scav2);
	repairUntilNoEnergy(*scav3);
	delete scav3;
}
