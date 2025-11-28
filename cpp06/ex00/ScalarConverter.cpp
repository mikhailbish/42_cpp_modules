#include "ScalarConverter.hpp"

//char
//int
//float
//double
/*
bool ScalarConverter::_isValidDouble(const std::string &text)
{
	try {
		size_t endIdx;
		double res = stod(text, &endIdx);
		if (text[endIdx])
			return (false);
		return (true;
	}
	catch (std::exception &e)
	{
		return (false);
	}
}
*/

std::string ScalarConverter::_resolvedDouble(const std::string &text)
{
	try {
		size_t endIdx;
		double res = stod(text, &endIdx);
		if (text[endIdx])
			return ("impossible");
		std::ostringstream str;
		str << res;
		return str.str();
	}
	catch (std::exception &e)
	{
		return ("impossible");
	}
}

std::string ScalarConverter::_resolvedInteger(const std::string &text)
{
	try {
		size_t endIdx;
		int res = stoi(text, &endIdx, 10);
		if (text[endIdx])
			return ("impossible");
		std::ostringstream str;
		str << res;
		return str.str();
	}
	catch (std::exception &e)
	{
		return ("impossible");
	}
}
std::string ScalarConverter::_resolvedFloat(const std::string &text)
{
	try {
		size_t endIdx;
		float res = stof(text, &endIdx);
		if (text[endIdx])
			return ("impossible");
		std::ostringstream str;
		str.setf(std::ios_base::fixed);
		str << std::setprecision(1) << std::fixed << res;
		return str.str();
	}
	catch (std::exception &e)
	{
		return ("impossible");
	}
}
std::string ScalarConverter::_resolvedChar(const std::string &text)
{
	try {
		size_t endIdx;
		int res = stoi(text, &endIdx, 10);
		if (text[endIdx])
			return ("impossible");
		if (res < (int)' ' || res > (int)'~')
			return ("impossible");
		std::ostringstream str;
		str << (char)res;
		return str.str();
	}
	catch (std::exception &e)
	{
		return ("impossible");
	}
}

void ScalarConverter::convert(const std::string &text)
{
	std::cout << "char: " << _resolvedChar(text) << std::endl;
	std::cout << "int: " << _resolvedInteger(text) << std::endl;
//	std::cout.setf(std::ios_base::)
	std::cout << "float: " << _resolvedFloat(text) << std::endl;
	std::cout << "double: " << _resolvedDouble(text) << std::endl;
}
