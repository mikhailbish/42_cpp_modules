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
}



