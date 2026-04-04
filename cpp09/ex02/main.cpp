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
		generateJacobsthalSequence(argc / 2 + 1);
		auto vStart = std::chrono::steady_clock::now();
		std::vector<int> numsV;
		fillContainer(argc, argv, numsV);
		pMergeInsertion(numsV);
		auto vEnd = std::chrono::steady_clock::now();
		auto vDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(vEnd - vStart);

		auto dStart = std::chrono::steady_clock::now();
		std::deque<int> numsD;
		fillContainer(argc, argv, numsD);
		pMergeInsertion(numsD);
		auto dEnd = std::chrono::steady_clock::now();
		auto dDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(dEnd - dStart);

		std::cout << "Before: ";
		printContainerizedNumbers(argv + 1, argc - 1);
		std::cout << "After:  ";
		printContainerizedNumbers(numsV, numsV.size());
	//	printContainerizedNumbers(numsD, numsD.size());
		if (!std::is_sorted(numsV.begin(), numsV.end()))
			throw 1;
		if (!std::is_sorted(numsD.begin(), numsD.end()))
			throw 1;
		std::cout << "Time to process a range of " << numsV.size() << " elements with std::vector: " << vDuration << std::endl;
		std::cout << "Time to process a range of " << numsV.size() << " elements with std::deque:  " << dDuration << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error when sorting" << std::endl;
	}

	return (0);
}
