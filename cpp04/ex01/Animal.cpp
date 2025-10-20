#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
	type = "Animal";
}

Animal::Animal(Animal &other)
{
	std::cout << "Animal copy constructor" << std::endl;
	type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << type << " says Hell0 there" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
