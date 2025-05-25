#include <iostream>

char *getUpperCaseString(char *str)
{
	
	for(size_t i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
	return (str);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		if (std::cout)
			return (0);
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		std::cout << getUpperCaseString(argv[i]);
	}
	std::cout << std::endl;
	if (!std::cout)
		return (3);
	return (0);
}
