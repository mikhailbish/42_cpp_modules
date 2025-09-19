#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed const a(10.5f);
	Fixed const b( 10.5f );
	Fixed const c( 42.42f );
	Fixed const e( -42.42f );
	Fixed const d( b );
	Fixed i = 0;
//	a = Fixed( 1234.4321f );
	std::cout << ((c >= b) ? "True" : "False") << std::endl;
	std::cout << ((a > b) ? "True" : "False") << std::endl;
	std::cout << ((a == b) ? "True" : "False") << std::endl;
	std::cout << ((a != b) ? "True" : "False") << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << (a - b) << std::endl;
	std::cout << "e:"  << e << std::endl;
	std::cout << "multiplication (100):" << (a * b) << std::endl;
	Fixed f = a / b;
	std::cout << "division: " << f << std::endl;
	Fixed g = c / e;
	std::cout << "division: " << g << std::endl;
	Fixed h = c / b;
	std::cout << "division: " << h << std::endl;
	std::cout << "starting i " << i << std::endl;
	std::cout << "postfix increment i " << i++ << std::endl;
	std::cout << "i after postfix increment " << i << std::endl;
	std::cout << "prefix increment i " << ++i << std::endl;
	std::cout << "i after prefix increment " << i << std::endl;
	std::cout << "postfix decrement i " << i-- << std::endl;
	std::cout << "i after postfix decrement " << i << std::endl;
	std::cout << "prefix decrement i " << --i << std::endl;
	std::cout << "i after prefix decrement" << i << std::endl;
	
	std::cout << "min of 10.5 and 42.42 is " << Fixed::min(a, c) << std::endl;
	std::cout << "max of 10.5 and 42.42 is " << Fixed::max(a, c) << std::endl;
	std::cout << "min of " << f << " and "<< g << " is " << Fixed::min(f, g) << std::endl;
	std::cout << "max of " << f << " and "<< g << " is " << Fixed::max(f, g) << std::endl;
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
