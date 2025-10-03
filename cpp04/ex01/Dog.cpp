#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	head = new (std::nothrow) Brain();
}

void Dog::makeSound() const
{
	std::cout << type << " says woof" << std::endl;
}

Dog::~Dog()
{
	if (head != nullptr)
		delete head;
}

Brain *Dog::getBrain() const
{
	return head;
}
