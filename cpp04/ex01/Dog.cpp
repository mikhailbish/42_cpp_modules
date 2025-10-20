#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor" << std::endl;
	head = new (std::nothrow) Brain();
}

Dog::Dog(Dog &other)
{
	std::cout << "Dog copy constructor" << std::endl;
	Brain *otherBrain = other.getBrain();
	if (otherBrain == nullptr)
		head = new (std::nothrow) Brain();
	else
		head  = new (std::nothrow) Brain(*otherBrain);
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment constructor" << std::endl;
	if (this == &other)
		return *this;
	Brain *otherBrain = other.getBrain();
	if (this->head != nullptr)
		delete this->head;
	if (otherBrain == nullptr)
		head = new (std::nothrow) Brain();
	else
		head  = new (std::nothrow) Brain(*otherBrain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << type << " says woof" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	if (head != nullptr)
		delete head;
}

Brain *Dog::getBrain() const
{
	return head;
}
