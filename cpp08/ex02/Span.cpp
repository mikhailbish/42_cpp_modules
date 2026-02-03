#include "Span.hpp"

Span::Span(unsigned int num) : N(num)
{}

Span::Span(const Span &other) : Span(other.N)
{
	_storage = other._storage;
}

Span &Span::operator=(Span &other)
{
	if (&other == this)
		return (*this);
	N = other.N;
	_storage = other._storage;
	return (*this);
}

void Span::addNumber(int number)
{
	if (_storage.size() < N)
		_storage.insert(number);
	else
		throw InadequateAmountOfNumbersException();
}

const char *Span::InadequateAmountOfNumbersException::what() const noexcept
{
	return "Wrong number amount for the operation";
}

unsigned int Span::_getDistance(int num1, int num2) const
{
	if (num1 == num2)
		return (0);
	if (num1 < num2)
		return _getDistance(num2, num1);
	return static_cast<unsigned int>(num1 - num2);
}

unsigned int Span::shortestSpan() const
{
	int prevNum;
	bool firstIter = true;
	unsigned int ss = -1;
	if (_storage.size() < 2)
		throw InadequateAmountOfNumbersException();
	for (const int &num : _storage)
	{
		if (!firstIter)
		{
			if (ss > _getDistance(prevNum, num))
				ss = _getDistance(prevNum, num);
		}
		firstIter = false;
		prevNum = num;
	}
	return ss;
}

unsigned int Span::longestSpan() const
{
	if (_storage.size() < 2)
		throw InadequateAmountOfNumbersException();
	return _getDistance(*_storage.begin(), *(std::prev(_storage.end())));
}
