#include "PmergeMe.hpp"

bool validateNumericalString(std::string number)
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
	
	return (0);
}
