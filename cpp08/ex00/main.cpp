#include <vector>
#include <iostream>
#include "easyfind.h"

int main()
{
	try
	{
		std::vector<int> myvec;
		myvec.push_back(5);
		myvec.push_back(8);
		myvec.push_back(2);
		myvec.push_back(4);
		myvec.push_back(0);
		myvec.push_back(5);
		auto meow = easyfind(myvec, 4);
		if (meow != myvec.end())
			std::cout << (*meow) << std::endl;
		else
			std::cout << "not found" << std::endl;
		*meow = 2;
		std::cout << (*meow) << std::endl;
		const std::vector<int> some = {123, 12312321 ,123123 ,12,22};
		auto wow = easyfind(some, 4);
		if (wow != some.end())
			std::cout << (*wow) << std::endl;
		else
			std::cout << "not found" << std::endl;
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
	return (0);
}
