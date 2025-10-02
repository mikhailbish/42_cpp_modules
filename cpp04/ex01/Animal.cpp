#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
}

void Animal::makeSound() const
{
	std::cout << type << " says Hell0 there" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
