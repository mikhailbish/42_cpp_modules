#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
}

void Cat::makeSound() const
{
	std::cout << type << " says meow" << std::endl;
}

