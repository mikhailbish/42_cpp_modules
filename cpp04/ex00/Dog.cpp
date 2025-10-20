#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor" << std::endl;
	type = "Dog";
}

Dog::Dog(Dog &other)
{
	std::cout << "Dog copy constructor" << std::endl;
	type = other.type;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment constructor" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << type << " says woof" << std::endl;
}
