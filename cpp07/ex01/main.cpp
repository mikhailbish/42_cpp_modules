#include <string>
#include <iostream>
#include "iter.hpp"

void addYo(std::string &str)
{
	str += "yo";
}

void addFive(int &num)
{
	num += 5;
}

void setZero(int &num)
{
	num = 0;
}

int main()
{
	std::string strs[5];
	std::string *strsPtr = &strs[0];
	::iter(strsPtr, 5, &addYo);
	::iter(strsPtr, 5, &(print<std::string>));
	int nums[5];
	::iter(&nums[0], 5, &setZero);
	::iter(&nums[0], 5, &addFive);
	::iter(&nums[0], 5, &(print<int>));
}
