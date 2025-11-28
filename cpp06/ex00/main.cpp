#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Provide one parameter" << std::endl;
		return (1);
	}
	try {
		const std::string text(argv[1]);
		ScalarConverter::convert(text);
	} catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
