#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat &other)
{
	std::cout << "Cat copy constructor" << std::endl;
	type = other.type;
}


Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment constructor" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << type << " says meow" << std::endl;
}

