#include "Fixed.hpp"
#include <string>

Fixed::Fixed(void) {
	_value = 0;
	std::cout << "fp constructor" << std::endl;
}

Fixed::Fixed(Fixed &other) {
	std::cout << "fp copy constructor" << std::endl;
	this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "fp copy assignment operator overloaded" << std::endl;
	if (this != &f)
		this->_value = f._value;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "get raw bits is called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "set raw bits is called" << std::endl;
	this->_value = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Fp Destructor" << std::endl;

}
