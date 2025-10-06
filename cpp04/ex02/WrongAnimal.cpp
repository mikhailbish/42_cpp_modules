#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
}

void WrongAnimal::makeSound() const
{
	std::cout << "You hear very wrong sounds" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}
