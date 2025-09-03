#include "Harl.hpp"

int main()
{
	try {
		Harl sofa_expert;
		std::cout << "[DEBUG]" << std::endl;
		sofa_expert.complain("DEBUG");
		std::cout << "[INFO]" << std::endl;
		sofa_expert.complain("INFO");
		std::cout << "[WARNING]" << std::endl;
		sofa_expert.complain("WARNING");
		std::cout << "[ERROR]" << std::endl;
		sofa_expert.complain("ERROR");
		std::cout << "[asdasd]" << std::endl;
		sofa_expert.complain("asdasd");
	}
	catch (...)
	{
		std::cout << "Something went wrong, an error was caught!" << std::endl;
	}
}
