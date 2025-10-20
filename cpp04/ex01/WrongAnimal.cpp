#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	type = other.type;
}


WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignment constructor" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "You hear very wrong sounds" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}
