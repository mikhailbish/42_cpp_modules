#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <exception>
#include <iostream>
template<typename T>
class Array {
	private:
		T *_array = nullptr;
		unsigned int _length;
	public:
		unsigned int size() const
		{ return _length; }
		Array() : _length(0) {}
		Array(unsigned int n) : _length(n)
		{
			_array = new T[n];
			if (_array == nullptr)
				throw std::bad_alloc();
		}
		Array(const Array &other) :  _length(other._length)
		{
			_array = new T[_length];
			if (_array == nullptr)
				throw std::bad_alloc();
			for (unsigned int i = 0; i < other._length; ++i)
			{
				_array[i] = other._array[i];
			}
		}
		Array &operator=(const Array &other)
		{
			if (this == &other)
				return (*this);
			delete[] _array;
			_length = other._length;
			_array = new T[_length];
			if (_array == nullptr)
				throw std::bad_alloc();
			for (unsigned int i = 0; i < other.size(); ++i)
			{
				_array[i] = other[i];
			}
			return *this;
		}
		~Array(){
			delete[] _array;
		}
		T& operator[](const unsigned int index) const {
			if (index >= _length)
				throw std::out_of_range("index too large");
			return _array[index];
		}
};

/*	Testing helpers		*/
template<typename T>
void iter(Array<T> &address, const int length, void (func)(T&))
{
	int i = 0;
	while (i < length)
	{
		func(address[i]);
		i++;
	}
}

template<typename T>
void iter(Array<T> &address, const int length, void (func)(const T&))
{
	int i = 0;
	while (i < length)
	{
		func(address[i]);
		i++;
	}
}

template<typename T>
void print(const T &toPrint)
{
	std::cout << toPrint << std::endl;
}

#endif
