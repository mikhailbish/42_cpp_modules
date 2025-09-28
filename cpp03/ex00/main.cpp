#include "ClapTrap.hpp"

void attackUntilNoEnergy(ClapTrap &first, ClapTrap &second)
{
	while (first.getEnergy())
	{
		first.attack(second.getName());
		second.takeDamage(first.getAttackDamage());
	}
	first.attack(second.getName());
	second.takeDamage(first.getAttackDamage());
}
void repairUntilNoEnergy(ClapTrap &first)
{
	while (first.getEnergy())
	{
		first.beRepaired(10);
	}
	first.beRepaired(10);
}

int main()
{
	ClapTrap first("First");
	ClapTrap second("second");
	attackUntilNoEnergy(first, second);
	repairUntilNoEnergy(second);
}
