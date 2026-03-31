#include "RPN.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		RPN calculator;
		for (char c : std::string(argv[1]))
		{
			calculator.processChar(c);
		}
		std::cout << calculator.getResult() << std::endl;
	} catch(...) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
