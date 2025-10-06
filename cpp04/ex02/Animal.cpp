#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "animal constructor" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << type << " says Hell0 there" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

Animal::~Animal()
{
	std::cout << "animal destructor" << std::endl;
}
