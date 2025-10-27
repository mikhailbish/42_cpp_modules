#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor" << std::endl;
	head = new (std::nothrow) Brain();
}

Cat::Cat(Cat &other)
{
	std::cout << "Cat copy constructor" << std::endl;
	Brain *otherBrain = other.getBrain();
	if (otherBrain == nullptr)
		head = new (std::nothrow) Brain();
	else
		head  = new (std::nothrow) Brain(*otherBrain);
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment constructor" << std::endl;
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

void Cat::makeSound() const
{
	std::cout << type << " says meow" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	if (head != nullptr)
		delete head;
}

Brain *Cat::getBrain() const
{
	return head;
}
