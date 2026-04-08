#include "RPN.hpp"

void RPN::processChar(char c)
{
	if (c <= '9' && c >= '0')
	{
		if (!_lastIsSpace)
			throw 1;
		_lastIsSpace = false;
		_processNumber(static_cast<double>(c - '0'));
	}
	else if (c == '/' || c == '+' || c == '-' || c == '*')
	{
		if (!_lastIsSpace)
			throw 1;
		_lastIsSpace = false;
		_processSign(c);
	}
	else if (c == ' ')
	{
		if (_lastIsSpace)
			throw 1;
		_lastIsSpace = true;
	}
	else
		throw 1;
}

void RPN::_processNumber(double number)
{
	_holder.push(number);
}

void RPN::_checkOverflow(double num)
{
	if (std::isinf(num))
		throw 1;
}

void RPN::_processSign(char sign)
{
	if (_holder.size() < 2)
		throw 1;
	double temp = _holder.top();
	_holder.pop();
	if (sign == '+')
	{
		_holder.top() += temp;
		_checkOverflow(_holder.top());
	}
	else if (sign == '-')
	{
		_holder.top() -= temp;
		_checkOverflow(_holder.top());
	}
	else if (sign == '*')
	{
		_holder.top() *= temp;
		_checkOverflow(_holder.top());
	}
	else if (sign == '/')
	{
		if (temp == 0)
			throw 1;
		_holder.top() /= temp;
	}
}

double RPN::getResult()
{
	if (_holder.size() != 1)
		throw 1;
	return _holder.top();
}
