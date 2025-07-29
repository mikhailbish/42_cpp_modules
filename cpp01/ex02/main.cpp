#include <string>
#include <iostream>
int main()
{
	
	std::string og_text;
	try
	{
      		og_text = "HI THIS IS BRAIN";
	}
	catch (...)
	{
		return 1;
	}
	std::string *stringPTR = &og_text;
	const std::string &stringREF = og_text;
	std::cout << "str address: " << &og_text << std::endl;
	std::cout << "ptr address: " << stringPTR << std::endl;
	std::cout << "ref address: " << &stringREF << std::endl;
	std::cout << "str value: " << og_text << std::endl;
	std::cout << "ptr value: " << *stringPTR << std::endl;
	std::cout << "ref value: " << stringREF << std::endl;
	return (0);
}
