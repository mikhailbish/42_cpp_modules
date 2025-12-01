#include "ScalarConverter.hpp"

bool ScalarConverter::_isValidDouble(const std::string &text)
{
	try {
		size_t endIdx;
		double doubleNumber = stod(text, &endIdx);
		if (text[endIdx])
			return (false);
		if (std::isnan(doubleNumber) || std::isinf(doubleNumber))
			return (true);
		if (static_cast<long double>(doubleNumber) - stold(text) != 0)
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
		if (!( !text[endIdx] || (text[endIdx] == 'f' && (text.length() - 1 == endIdx) && std::isdigit( text[endIdx - 1]))))
			return (false);
		if (std::isnan(fnum) || std::isinf(fnum))
			return (true);
		if ((static_cast<double>(fnum) - stod(text)) != 0)
			return (false);
		return (true);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}

std::string ScalarConverter::_resolve(double num)
{
	std::ostringstream str;
	if (_isAccurateConversion<double, long>(num))
		str << std::setprecision(1) << std::fixed << num;
	else
		str << std::setprecision(std::numeric_limits<long double>::digits10)<< num;
	return str.str();
}

std::string ScalarConverter::_resolve(float num)
{
	std::ostringstream str;
	if (_isAccurateConversion<float, long>(num))
		str << std::setprecision(1) << std::fixed << num << "f";
	else
		str << std::setprecision(std::numeric_limits<long double>::digits10)<< num << "f";
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
	bool 	validDouble	= _isValidDouble(text);
	bool	validFloat	= _isValidFloat(text);
	if (validDouble)
		ScalarConverter::_resolveOutput<double>(stod(text), true);
	else if (validFloat)
		ScalarConverter::_resolveOutput<float>(stof(text), true);
	else
		ScalarConverter::_resolveOutput<int>(0, false);
}
