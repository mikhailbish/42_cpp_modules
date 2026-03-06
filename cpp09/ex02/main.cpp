#include "PmergeMe.hpp"
#include <iostream>
#include <string>

bool validateNumericalString(std::string &&number)
{
	try
	{
		size_t index;
		int num = stoi(number, &index);
		if (num < 1 || number[index])
			return false;
	} catch (...)
	{
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int index = 0;
	while (index < argc)
	{
		if ( index && !validateNumericalString(std::string(argv[index])))
		{
			std::cout << "Erroneous param" << std::endl;
			return 1;
		}
		if (index)
			std::cout << argv[index] << std::endl;
		index++;
	}
	return (0);
}
