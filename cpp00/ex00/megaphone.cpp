#include <iostream>
#include <string>

std::string getUpperCaseString(std::string str)
{
	
	for(size_t i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return (str);
}

int main(int argc, char *argv[])
{
//	std::string str;
	(void)argv;

//	str = "";
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
	//	str += argv[i];
		std::cout << argv[i];
	}
	std::cout << std::endl;
//	str = getUpperCaseString(str);
//	std::cout << str << std::endl;

	/*
	try
	{
		while(1)
		;
	}
	catch (...)
	{
		//asdasd
		return(1);
	}
	*/
	return (0);
}
