#include "Fixed.hpp"

Fixed::Fixed(void) {
	_value = 0;
}

Fixed::Fixed(const Fixed &other) {
	this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	if (this != &f)
		this->_value = f._value;
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed::~Fixed(void)
{
}

int Fixed::toInt(void) const
{
	return (_value >> _bitlength);
}

Fixed::Fixed(const int number)
{
//	std::cout << "Int constructor called" << std::endl;
	_value = number << _bitlength;
}

Fixed::Fixed(const float number)
{
//	std::cout << "Float constructor called" << std::endl;
	_value = (int)std::roundf(number * (1 << _bitlength));
}

float Fixed::toFloat(void) const
{
	return ((float)(_value) / (1 <<_bitlength)) ;
}

std::ostream& operator<<(std::ostream& os, const Fixed& number)
{
	os << number.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed num = Fixed();
	num.setRawBits(this->_value + other._value);
	return (num);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed num = Fixed();
	num.setRawBits(this->_value - other._value);
	return (num);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed((this->toFloat() * other.toFloat())));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed((this->toFloat() / other.toFloat())));
}

Fixed& Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed result;
	result.setRawBits(this->_value);
	this->_value++;
	return (result);
}

Fixed Fixed::operator--(int)
{
	Fixed result;
	result.setRawBits(this->_value);
	this->_value--;
	return (result);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	return (first < second ? first : second );
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	return (first < second ? first : second );
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	return (first > second ? first : second );
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	return (first > second ? first : second );
}
