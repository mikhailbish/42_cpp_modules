#pragma once

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		iterator begin()
		{
			std::cout << "iterator begin" << std::endl;
			return (this->c.begin());
		}
		iterator end()
		{
			std::cout << "iterator end" << std::endl;
			return (this->c.end());
		}
		reverse_iterator rbegin()
		{
			std::cout << "iterator rbegin" << std::endl;
			return (this->c.rbegin());
		}
		reverse_iterator rend()
		{
			std::cout << "iterator rend" << std::endl;
			return (this->c.rend());
		}
		const_iterator begin() const
		{
			std::cout << "iterator begin const" << std::endl;
			return (this->c.begin());
		}
		const_iterator end() const
		{
			std::cout << "iterator end const" << std::endl;
			return (this->c.end());
		}
		const_reverse_iterator rbegin() const
		{
			std::cout << "iterator rbegin const" << std::endl;
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const
		{
			std::cout << "iterator rend const" << std::endl;
			return (this->c.rend());
		}
};
