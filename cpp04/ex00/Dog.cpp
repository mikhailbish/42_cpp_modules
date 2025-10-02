#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
}

void Dog::makeSound() const
{
	std::cout << type << " says woof" << std::endl;
}
