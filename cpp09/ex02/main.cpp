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
		long num = stoi(number, &index);
		if (number[index])
			return false;
		if (num < 1)
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
	try
	{
		//prep jacobstal
		// start time count
		std::vector<int> numsV;
		fillContainer(argc, argv, numsV);
		pMergeInsertion(numsV);
		// end time count
		std::cout << "----------------------------------------" << std::endl;
		// start time count
		std::deque<int> numsD;
		fillContainer(argc, argv, numsD);
		pMergeInsertion(numsD);
		// end time count
		std::cout << "Before: ";
		printContainerizedNumbers(argv + 1, argc - 1);
		std::cout << "After:  ";
		printContainerizedNumbers(numsV, numsV.size());
//TODO: update numbers
		std::cout << "Time to process a range of " << numsV.size() << " elements with std::vector: " << 62.14389 <<" us" << std::endl;
		std::cout << "Time to process a range of " << numsV.size() << " elements with std::deque:  " << 62.14389 <<" us" << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error when sorting" << std::endl;
	}
	return (0);
}
