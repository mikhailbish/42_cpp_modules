#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	head = new (std::nothrow) Brain();
}

void Cat::makeSound() const
{
	std::cout << type << " says meow" << std::endl;
}

Cat::~Cat()
{
	if (head != nullptr)
		delete head;
}

Brain *Cat::getBrain() const
{
	return head;
}
