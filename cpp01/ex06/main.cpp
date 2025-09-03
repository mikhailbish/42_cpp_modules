#include "Harl.hpp"

int main(int argc, char *argv[])
{
	try {
		Harl sofa_expert;
		if (argc < 2)
		{
			sofa_expert.complain("");
			return (0);
		}
		sofa_expert.complain(argv[1]);
	}
	catch (...)
	{
		std::cout << "Something went wrong, an error was caught!" << std::endl;
	}
	return (0);
}
