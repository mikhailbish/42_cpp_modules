#include "DiamondTrap.hpp"

void attackUntilNoEnergy(DiamondTrap &first, DiamondTrap &second)
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

void repairUntilNoEnergy(DiamondTrap &first)
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
	DiamondTrap diam("wow");
	DiamondTrap *diamPtr = new(std::nothrow)DiamondTrap("heh");
	if (diamPtr == nullptr)
		return 1;

	ClapTrap *cpptr;
	ScavTrap *scptr;
	cpptr = &diam;
	cpptr->attack("wooooow");
	scptr = &diam;
	scptr->guardGate();
	scptr->attack("zxxczxczxczxcxzczxczxczxczxcxzcxzcxzczxccx");
	diamPtr->whoAmI();
	diamPtr->attack("yo");
	delete diamPtr;
	return 0;
}
