#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " has risen from the ground" << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << this->_name << " has returned to the ground" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
