#include "FragTrap.hpp"

void attackUntilNoEnergy(FragTrap &first, FragTrap &second)
{
	while (first.getEnergy())
	{
		first.attack(second.getName());
		second.takeDamage(first.getAttackDamage());
	}
	first.attack(second.getName());
}

void repairUntilNoEnergy(FragTrap &first)
{
	while (first.getEnergy())
	{
		first.beRepaired(10);
	}
	first.beRepaired(10);
}

int main()
{
	FragTrap frag1("yo");
	FragTrap frag2("wow");
	frag1.guardGate();
	frag1.highFivesGuys();
	attackUntilNoEnergy(frag1, frag2);
	repairUntilNoEnergy(frag2);
}
