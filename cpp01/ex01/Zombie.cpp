#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
//	_name = 0;
	std::cout << "someone has risen from the ground" << std::endl;
}

Zombie::Zombie(std::string name)
{
//	this->_name = name;
	setName(&name);
	std::cout << this->_name << " has risen from the ground" << std::endl;
}
Zombie::~Zombie(void)
{
	if (this->_name.length())
		std::cout << this->_name << " has returned to the ground" << std::endl;
	else
		std::cout << "someone has returned to the ground" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string *name)
{
	if (!name)
		return;
	_name = *name;
}
