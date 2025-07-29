#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name), _weapon(nullptr)
{
}

void HumanB::attack()
{
	if (_weapon == nullptr)
		std::cout << _name << " attacks without a weapon" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;

}
