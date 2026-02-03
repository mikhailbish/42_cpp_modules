#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>
template <typename T>
typename T::const_iterator easyfind(const T &container, const int num)
{
	return find(container.begin(), container.end(), num);
}

template <typename T>
typename T::iterator easyfind(T &container, const int num)
{
	return find(container.begin(), container.end(), num);
}

#endif
