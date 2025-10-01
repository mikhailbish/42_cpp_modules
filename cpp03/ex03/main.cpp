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
	repairUntilNoEnergy(diam);
	DiamondTrap *diamPtr = new DiamondTrap("heh");
	delete diamPtr;
/*
	FragTrap frag1("yo");
	FragTrap frag2("wow");
	frag1.guardGate();
	frag1.highFivesGuys();
	attackUntilNoEnergy(frag1, frag2);
	repairUntilNoEnergy(frag2);
*/
}
