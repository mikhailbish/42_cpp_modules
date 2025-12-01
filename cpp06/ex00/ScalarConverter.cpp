#include "ScalarConverter.hpp"

bool ScalarConverter::_isValidLong(const std::string &text)
{
	try {
		size_t endIdx;
		stol(text, &endIdx);
		if (!((text[endIdx] == 'f' && text.length() - 1 == endIdx ) ||  !text[endIdx]))
			return (false);
		return (true);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}

bool ScalarConverter::_isValidDouble(const std::string &text)
{
	try {
		size_t endIdx;
		double doubleNumber = stod(text, &endIdx);
		long double longDoubleNumber = stold(text, &endIdx);
		if (!((text[endIdx] == 'f' && text.length() - 1 == endIdx ) ||  !text[endIdx]))
			return (false);
		if (std::isnan(doubleNumber) || std::isinf(doubleNumber))
			return (true);
		if (static_cast<long double>(doubleNumber) - longDoubleNumber != 0)
			return (false);
		return (true);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}

bool ScalarConverter::_isValidFloat(const std::string &text)
{
	try {
		size_t endIdx;
		float fnum = stof(text, &endIdx);
		if (!((text[endIdx] == 'f' && text.length() - 1 == endIdx ) ||  !text[endIdx]))
			return (false);
		if (std::isnan(fnum) || std::isinf(fnum))
			return (true);
		if (!((static_cast<double>(fnum) - stod(text)) == 0))
			return (false);
		return (true);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}

bool ScalarConverter::_isValidInt(const std::string &text)
{
	try {
		size_t endIdx;
		stoi(text, &endIdx, 10);
		if (!((text[endIdx] == 'f' && text.length() - 1 == endIdx ) ||  !text[endIdx]))
			return (false);
		return (true);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}

bool ScalarConverter::_isValidChar(const std::string &text)
{
	try {
		size_t endIdx;
		int res = stoi(text, &endIdx, 10);
		if (!((text[endIdx] == 'f' && text.length() - 1 == endIdx ) ||  !text[endIdx]))
			return (false);
		if (res < std::numeric_limits<char>::min() || res > std::numeric_limits<char>::max())
			return (false);
		return (true);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}

std::string ScalarConverter::_resolve(double num, bool isValidLong)
{
	std::ostringstream str;
	if (isValidLong)
		str << std::setprecision(1) << std::fixed << num;
	else
		str << num;
	return str.str();
}

std::string ScalarConverter::_resolve(float num, bool isValidLong)
{
	std::ostringstream str;
	if (isValidLong)
		str << std::setprecision(1) << std::fixed << num << "f";
	else
		str << num << "f";
	return str.str();
}
std::string ScalarConverter::_resolve(int num)
{
	std::ostringstream str;
	str << num;
	return str.str();
}

std::string ScalarConverter::_resolve(char num)
{
	std::ostringstream str;
	if (std::isprint(static_cast<unsigned char>(num)))
	{
		str << "'" << num << "'";
		return str.str();
	}
	return "Non displayable";
}

void ScalarConverter::convert(const std::string &text)
{
	std::string	imp 	= "impossible";
	bool 	validLong	= _isValidLong(text);
	bool 	validDouble	= _isValidDouble(text);
	bool	validFloat	= _isValidFloat(text);
	bool	validInt	= _isValidInt(text);
	bool	validChar	= _isValidChar(text);
	double	numDouble	= validDouble	? stod(text)			: 0;
	float	numFloat	= validFloat	? static_cast<float>(numDouble)	: 0;
	int	numInt		= validInt	? static_cast<int>(numDouble)	: 0;
	char	numChar		= validChar	? static_cast<char>(numDouble)	: 0;

	std::cout << "char: "	<< (validChar	? _resolve(numChar)			: imp) << std::endl;
	std::cout << "int: "	<< (validInt	? _resolve(numInt) 			: imp) << std::endl;
	std::cout << "float: "	<< (validFloat	? _resolve(numFloat, validLong)		: imp) << std::endl;
	std::cout << "double: " << (validDouble ? _resolve(numDouble, validLong)	: imp) << std::endl;
}
