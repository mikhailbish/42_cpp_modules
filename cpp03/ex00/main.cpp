#include "ClapTrap.hpp"

int main()
{
	ClapTrap first("First");
	ClapTrap second("second");

	for (int i = 0; i < 20; i++)
	{
		first.attack(second.getName());
//		second.
	}
	for (int i = 0; i < 20; i++)
	{
		first.beRepaired(10);
	}
}
