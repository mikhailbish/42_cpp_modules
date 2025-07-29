#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>
/*
void diffScope(HumanB *bhuman)
{
	Weapon some = Weapon("test");
	bhuman->setWeapon(&some);
	some.setType("Super weapon");
}

int main()
{
	std::string nameB = "other name";
	HumanB bhuman(nameB);
	{
		Weapon some("test");
		bhuman.setWeapon(&some);
		bhuman.attack();
		some.setType("Super weapon");
		bhuman.attack();
	}
	bhuman.attack();
	return (0);
}
*/
/*
int main()
{
	Weapon some = Weapon("test");
	std::string nameA = "dude";
	std::string nameB = "other name";
	HumanA ahuman = HumanA(nameA, some);
	HumanB bhuman = HumanB(nameB);
	ahuman.attack();
	bhuman.attack();
	bhuman.setWeapon(some);
	bhuman.attack();
	some.setType("Super weapon");
	ahuman.attack();
	bhuman.attack();
	return (0);
}
*/
/*
int main()
{
	Weapon some = Weapon("test");
	std::string nameA = "dude";
	std::string nameB = "other name";
	HumanA ahuman = HumanA(nameA, some);
	HumanB bhuman = HumanB(nameB);
	ahuman.attack();
	bhuman.attack();
	bhuman.setWeapon(some);
	bhuman.attack();
	some.setType("Super weapon");
	ahuman.attack();
	bhuman.attack();
	return (0);
}
*/

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

