#include "ScavTrap.hpp"

void attackUntilNoEnergy(ScavTrap &first, ScavTrap &second)
{
	while (first.getEnergy())
	{
		first.attack(second.getName());
		second.takeDamage(first.getAttackDamage());
	}
	first.attack(second.getName());
}
void repairUntilNoEnergy(ScavTrap &first)
{
	while (first.getEnergy())
	{
		first.beRepaired(10);
	}
	first.beRepaired(10);
}

int main()
{
	ScavTrap scav1("yo");
	ScavTrap scav2("wow");
	scav1.guardGate();
	attackUntilNoEnergy(scav1, scav2);
	repairUntilNoEnergy(scav2);
}
