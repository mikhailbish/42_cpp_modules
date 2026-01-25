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

bool isPrime(int num)
{
	int i = 2;
	if (num == 2)
		return true;
	while (num / i >= i)
	{
		if (num % i == 0)
			return (false);
		i++;
	}
	return (true);
	
}

int getNextPrime()
{
	static int num = 1;
	num++;
	while (!isPrime(num))
	{
		num++;
	}
	return (num);
}

void setNextPrime(int &num)
{
	num = getNextPrime();
}

int main()
{
	std::string strs[5];
	std::string *strsPtr = &strs[0];
	int nums[5];
	const int numsnums[5] = { 1, 2, 3, 4, 5};
	
	::iter(strsPtr, 5, &addYo);
	::iter(strsPtr, 5, &(print<std::string>));
	::iter(&nums[0], 5, &setZero);
	::iter(&nums[0], 5, &addFive);
	::iter(&nums[0], 5, &(print<int>));
	::iter(&numsnums[0], 5, &(print<int>));

	try {	
		int *numsHeap = new int[300];
		::iter(numsHeap, 300, &setNextPrime);
		::iter(numsHeap, 300, &print);
		delete[] numsHeap;
		
	}
	catch (...)
	{
		std::cout << "alloc error" << std::endl;
	}


}
