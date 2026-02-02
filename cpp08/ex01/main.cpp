#include <iostream>
#include "Span.hpp"
#include <vector>

int main()
{
	try
	{
		Span  sp(10);
		sp.addNumber(9);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
	try
	{
		Span  sp(10);
		sp.addNumber(9);
		sp.addNumber(7);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(1);
		sp.addNumber(-1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(-1);
		sp.addNumber(-1);
		sp.addNumber(-1);
		sp.addNumber(-1);
		sp.addNumber(-1);
		sp.addNumber(-1);
		sp.addNumber(-1);
		sp.addNumber(-1);
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
	try
	{
		Span  sp(3);
		std::vector<int> nums;
		nums.push_back(1);
		nums.push_back(5);
		nums.push_back(10);
		nums.push_back(14);
		nums.push_back(290);
		nums.push_back(30);
		sp.addNumber(nums.begin(), nums.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
	return (0);
}
