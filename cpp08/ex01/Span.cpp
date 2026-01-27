#include "Span.hpp"

Span::Span()
{
	_storage = new int[N];
}

Span::Span(unsigned int num) : N(num), Span()
{}

Span::Span(const Span &other) : Span(other.N), _filled(other._filled)
{
	for (unsigned int i = 0; i < _filled; ++i)
	{
		_storage[i] = other._storage[i];
	}
}

Span &Span::operator=(const Span &other)
{
	delete[] _storage;
	_storage = new int[other.N];
	for (unsigned int i = 0; i < _filled; ++i)
	{
		_storage[i] = other._storage[i];
	}
}

Span::~Span()
{
	delete[] _storage;
}
