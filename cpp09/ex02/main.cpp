#include "PmergeMe.hpp"
/*
	steps:
		- collect validated numbers into container
		- break numbers into the pairs
		- identify the leaders of the pairs
		- sort the leaders and start to plan jacobsthal insertion of the smaller numbers
*/


bool validateNumericalString(std::string &&number)
{
	try
	{
		size_t index;
		stoi(number, &index);
		if (number[index])
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
		if (index && !validateNumericalString(std::string(argv[index])))
		{
			std::cerr << "Erroneous param" << std::endl;
			return 1;
		}
		index++;
	}
	pmergeInsert(argc, argv);
	return (0);
}
