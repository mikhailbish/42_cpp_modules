#include "Fixed.hpp"
#include <iostream>

#include <iomanip>
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
	/*
	Fixed largenum(((1 << 23) - 1) /512);
	Fixed largestnum((1 << 23) - 1);
	
	Fixed otherNum(512);
	Fixed resultNum = largenum * otherNum; 
	std::cout << "overflow on mulitiplication " << (resultNum == largestnum ? "Success" : "Fail") << std::endl;
	std::cout << "result num " << resultNum << "\n" << "largest number"  << largestnum << std::endl;
	*/
	Fixed largenum(((float)(1 << 23) - 1) /128);
//	float largenumFloat = (( (float)(1 << 23) - 1) /128);
	std::cout << "-------------------------------------------------------------------------------------\n";
//	std::cout << "largenum as float  :" << std::setprecision(15) << largenumFloat << std::endl;

	Fixed largestnum((1 << 23) - 1);
	
	Fixed otherNum(128);
	Fixed resultNum = largenum * otherNum; 
	std::cout << "overflow on mulitiplication " << (resultNum == largestnum ? "Success" : "Fail") << std::endl;
	std::cout << "result num " << resultNum << "\n" << "largest number"  << largestnum << std::endl;
//	std::cout << "large number: " << largenum << std::endl;
//	std::cout << "large number: " <<  << std::endl;
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
	float v1 = 1.00390625f;
	std::cout << "fracEdge1.00390625f as a float      :" << std::setprecision(15) << v1 << std::endl;

	float v2 = 1.00390620f;
	std::cout << "fracEdge1.00390620f as a float      :" << std::setprecision(15) << v2 << std::endl;
	Fixed u(1.00390625f);
	Fixed v(1.00390620f);
	std::cout << "fracEdge1.00390625f	:" << std::setprecision(15) << u << std::endl;
	std::cout << "fracEdge2.00390620f	:" << std::setprecision(15) << v << std::endl;
	std::cout << "fracEdge1 == fracEdge2	:" << (u == v) << std::endl;
	std::cout << "fracEdge1 != fracEdge2	:" << (u != v) << std::endl;
	return 0;
}
