#include "RPN.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
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
		std::cout << "Error" << std::endl;
	}
}
