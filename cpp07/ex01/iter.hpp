#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T *address, const int length, void (func)(T&))
{
	int i = 0;
	while (i < length)
	{
		func(address[i]);
		i++;
	}
}

template<typename T>
void iter(T *address, const int length, void (func)(const T&))
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
