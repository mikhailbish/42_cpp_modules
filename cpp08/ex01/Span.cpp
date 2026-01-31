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
		_storage.push_back(number);
	else
		throw InadequateAmountOfNumbersException();
}

const char *Span::InadequateAmountOfNumbersException::what() const noexcept
{
	return "Wrong number amount for the operation";
}

unsigned int shortestSpan() const
{
	if (_storage.size() < 2)
		throw InadequateAmountOfNumbersException();
//	return
}
unsigned int longestSpan() const
{
	if (_storage.size() < 2)
		throw InadequateAmountOfNumbersException();
//	return
}
