#include "Fixed.hpp"
#include <iostream>

#include <iomanip>

void testCase(std::string& prompt, bool outcome, std::string& messageFail, float num1, float num2, Fixed fixed1, Fixed fixed2)
{
	if (!outcome)
	{
		std::cout << prompt << ": " << messageFail << std::endl;
		std::cout << "Float1: " << num1 << std::endl;
		std::cout << "Float2: " << num2 << std::endl;
		std::cout << "Fixed1: " << fixed1 << std::endl;
		std::cout << "Fixed2: " << fixed2 << std::endl;
	}
}

//#define FIXED_MIN -8388608
//#define FIXED_MAX 8388607
#define FIXED_MIN -100000
#define FIXED_MAX 100000

float getFloatMin(float f1, float f2)
{
	return ( f1 < f2 ? f1 : f2);
}

float getFloatMax(float f1, float f2)
{
	return ( f1 > f2 ? f1 : f2);
}

float getMinFloatStep(float num)
{
	int fractBits = 8;
	float step = ((float)1) / (1<<fractBits);
	while ((num  + step) == num || fractBits != 0)
	{
		fractBits -= 1;
		if(fractBits )
		step = ((float)1) / (1<<fractBits);
	}
	return (step);

}

int main( void ) {
	std::string promptComparison = "comaparison prompt";
	std::string messageFail = "message fail";
	

	
	Fixed const a(10.5f);
	Fixed const b( 10.5f );
	Fixed const c( 42.42f );
	Fixed const e( -42.42f );
	Fixed const d( b );

	
	float num1 = FIXED_MIN;
	float num2 = FIXED_MAX;
//	double num1 = FIXED_MIN;
//	double num2 = FIXED_MAX;
	Fixed fixed1(num1);
	Fixed fixed2(num2);
	float step = getMinFloatStep(num1);
	
	while (num1 < FIXED_MAX || fixed1 < FIXED_MAX )
	{
		testCase( promptComparison, (num1 < num2) == (fixed1 < fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, (num1 > num2) == (fixed1 > fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, (num1 <= num2) == (fixed1 <= fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, (num1 >= num2) == (fixed1 >= fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, (num1 == num2) == (fixed1 == fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, (num1 != num2) == (fixed1 != fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, getFloatMin(num1, num2) == Fixed::min(fixed1, fixed2).toFloat(), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, getFloatMax(num1, num2) == Fixed::max(fixed1, fixed2).toFloat(), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, Fixed(num1 * num2) == (fixed1 * fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, Fixed(num1 / num2) == (fixed1 / fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, Fixed(num1 - num2) == (fixed1 - fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( promptComparison, Fixed(num1 + num2) == (fixed1 + fixed2), messageFail, num1, num2, fixed1, fixed2);
		fixed1++;
		fixed2--;
		step = getMinFloatStep(num1);
/*
		if (num1 + step == num1)
			fractBits--;
			num1 += 2 * step;
		else
*/
			num1 +=  step;
/*		if (num1 + step == num1)
			num1 -= 2 * step;
		else
*/
			num1 -= step;
//		num2 -= ((float)1) / (1<<8);
	
	}


/*
	num += ((float)1) / (1<<8);
	j(num);
	std::cout << "Float: " << num << std::endl;
	std::cout << "Fixed: " << j << std::endl;
*/
	return (0);


	Fixed i = 0;


//	testCase("test prompt", );
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
