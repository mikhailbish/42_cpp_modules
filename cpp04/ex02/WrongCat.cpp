#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &other)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	type = other.type;
}


WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment constructor" << std::endl;
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << type << " meows backwards" << std::endl;
}
