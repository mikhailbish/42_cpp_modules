#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
}

void WrongCat::makeSound() const
{
	std::cout << type << " meows backwards" << std::endl;
}
