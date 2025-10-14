#include "ClapTrap.hpp"

void attackUntilNoEnergy(ClapTrap &first, ClapTrap &second)
{
	if (!first.getHitPoints())
		return ;
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
	ClapTrap first("First");
	ClapTrap second("second");

	ClapTrap *wow = new (std::nothrow) ClapTrap("ClapTrapOnHeap");
	if (wow == nullptr)
		return (1);
	attackUntilNoEnergy(*wow, first);
	delete wow;
	attackUntilNoEnergy(first, second);
	repairUntilNoEnergy(second);
}
