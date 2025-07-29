#include "Weapon.hpp"

Weapon::Weapon(std::string initType)
{
	setType(initType);
}

Weapon::~Weapon()
{}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}

const std::string& Weapon::getType()
{
	return (this->type);
}
