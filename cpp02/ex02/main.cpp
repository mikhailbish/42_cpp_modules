#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
#define DISPLAY_PRECISION 30
#define FIXED_MIN -8388608
#define FIXED_MAX 8388607

void testCase(std::string& prompt, bool outcome, std::string& messageFail, float num1, float num2, Fixed fixed1, Fixed fixed2)
{
	if (!outcome)
	{
		std::cout << prompt << ": " << messageFail << std::endl;
		std::cout << "Float1: " << std::setprecision(DISPLAY_PRECISION) << num1 << std::endl;
		std::cout << "Float2: " << std::setprecision(DISPLAY_PRECISION) << num2 << std::endl;
		std::cout << "Fixed1: " << std::setprecision(DISPLAY_PRECISION) << fixed1 << std::endl;
		std::cout << "Fixed2: " << std::setprecision(DISPLAY_PRECISION) << fixed2 << std::endl;
	}
}



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
		if(fractBits)
			step = ((float)1) / (1<<fractBits);
		else
			step = 1;
	}
	return (step);

}

bool multiplicationOverUnderflowCheck(float num1, float num2)
{
	return ((double)num1 * (double)num2 > FIXED_MAX) || ((double)num1 * (double)num2 < FIXED_MIN);
}

bool additionOverUnderflowCheck(float num1, float num2)
{
	return ((double)num1 + (double)num2 > FIXED_MAX) || ((double)num1 + (double)num2 < FIXED_MIN);
}

bool substractionOverUnderflowCheck(float num1, float num2)
{
	return ((double)num1 - (double)num2 > FIXED_MAX) || ((double)num1 - (double)num2 < FIXED_MIN);
}

int main( void ) {
	std::string smallerThan = "Testing < operator";
	std::string biggerThan = "Testing > operator";
	std::string smallerEqual = "Testing <= operator";
	std::string biggerEqual = "Testing >= operator";
	std::string equal = "Testing == operator";
	std::string notEqual = "Testing != operator";
	std::string maxPrompt = "Testing Max";
	std::string minPrompt = "Testing Min";
	std::string multiplicationPrompt = "Testing *";
	std::string divisionPrompt = "Testing /";
	std::string sumPrompt = "Testing +";
	std::string substractionPrompt = "Testing -";
	std::string promptComparison = "comaparison prompt";
	std::string messageFail = "Comparison to an equivalent float operation failed";
	
	float num1 = FIXED_MIN;
	float num2 = FIXED_MAX;
	Fixed fixed1(num1);
	Fixed fixed2(num2);
	float step = getMinFloatStep(num1);
	int fixedSteps = 1;
	
	while (num1 < FIXED_MAX || fixed1 < FIXED_MAX )
	{
		testCase( smallerThan, (num1 < num2) == (fixed1 < fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( biggerThan, (num1 > num2) == (fixed1 > fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( smallerEqual, (num1 <= num2) == (fixed1 <= fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( biggerEqual, (num1 >= num2) == (fixed1 >= fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( equal, (num1 == num2) == (fixed1 == fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( notEqual, (num1 != num2) == (fixed1 != fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( minPrompt, getFloatMin(num1, num2) == Fixed::min(fixed1, fixed2).toFloat(), messageFail, num1, num2, fixed1, fixed2);
		testCase( maxPrompt, getFloatMax(num1, num2) == Fixed::max(fixed1, fixed2).toFloat(), messageFail, num1, num2, fixed1, fixed2);

		if (!multiplicationOverUnderflowCheck(num1, num2))
			testCase( multiplicationPrompt, Fixed(num1 * num2) == (fixed1 * fixed2), messageFail, num1, num2, fixed1, fixed2);
		testCase( divisionPrompt, Fixed(num1 / num2) == (fixed1 / fixed2), messageFail, num1, num2, fixed1, fixed2);

		if (!substractionOverUnderflowCheck(num1, num2))
			testCase( substractionPrompt, Fixed(num1 - num2) == (fixed1 - fixed2), messageFail, num1, num2, fixed1, fixed2);
		if (!additionOverUnderflowCheck(num1, num2))
			testCase( sumPrompt, Fixed(num1 + num2) == (fixed1 + fixed2), messageFail, num1, num2, fixed1, fixed2);


		step = getMinFloatStep(num1);
		fixedSteps = (int)(step / (((float)1) / (1<<8)));
		while(fixedSteps--)
		{
			fixed1++;
			fixed2--;
		}
		num1 +=  step;
		num2 -= step;
	
	}
	return (0);
}
