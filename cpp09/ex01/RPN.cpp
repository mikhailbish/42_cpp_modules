#include "RPN.hpp"

void RPN::processChar(char c)
{
	if (c <= '9' && c >= '0')
	{
		if (!_lastIsSpace)
			throw 1;
		_lastIsSpace = false;
		processNumber(static_cast<float>(c - '0'));
	}
	else if (c == '/' || c == '+' || c == '-' || c == '*')
	{
		if (!_lastIsSpace)
			throw 1;
		_lastIsSpace = false;
		processSign(c);
	}
	else if (c == ' ')
	{
		if (_lastIsSpace)
			throw 1;
		_lastIsSpace = true;
	}
}

void RPN::processNumber(float number)
{
	_holder.push(number);
}
// TODO: overflows?
void RPN::processSign(char sign)
{
	if (_holder.size() < 2)
		throw 1;
	float temp = _holder.top();
	_holder.pop();
	if (sign == '*')
		_holder.top() *= temp;
	else if (sign == '/')
		_holder.top() /= temp;
	else if (sign == '+')
		_holder.top() += temp;
	else if (sign == '-')
		_holder.top() -= temp;
}

float RPN::getResult()
{
	if (_holder.size() != 1)
		throw 1;
	return _holder.top();
}
