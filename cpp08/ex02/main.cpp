#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
	try {
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
//		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
		const MutantStack<int> cMstack = mstack;
		MutantStack<int>::const_iterator cpIt = cMstack.begin();
		MutantStack<int>::const_iterator cpIte = cMstack.end();
		MutantStack<int>::const_reverse_iterator rcpIt = cMstack.rbegin();
		MutantStack<int>::const_reverse_iterator rcpIte = cMstack.rend();
		while (cpIt != cpIte)
		{
			std::cout << *cpIt << std::endl;
			++cpIt;
		}
		while (rcpIt != rcpIte)
		{
			std::cout << *rcpIt << std::endl;
			++rcpIt;
		}
	
		std::stack<int> s(mstack);
		
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	try {
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		//std::cout << mstack.top() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);

		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	//	std::stack<int> s(mstack);
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
	return (0);
}
