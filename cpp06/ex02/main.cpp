#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>

Base *generate(void)
{
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << "generated A" << std::endl;
		return dynamic_cast<Base *>(new(std::nothrow)A());
	}
	if (random == 1)
	{
		std::cout << "generated B" << std::endl;
		return dynamic_cast<Base *>(new(std::nothrow)B());
	}
	std::cout << "generated C" << std::endl;
	return dynamic_cast<Base *>(new(std::nothrow)C());
}

void identify(Base *p)
{
	try {
		if (dynamic_cast<A *>(p))
			std::cout << "Pointer to " << "A" << std::endl;
		if (dynamic_cast<B *>(p))
			std::cout << "Pointer to " << "B" << std::endl;
		if (dynamic_cast<C *>(p))
			std::cout << "Pointer to " << "C" << std::endl;
	} catch (std::exception &e)
	{
		std::cout << "Error in identify ptr" << e.what() << std::endl;
	}
}

void identify(Base &p)
{
	try {
		A &refA = dynamic_cast<A &>(p);
		(void)refA;
		std::cout << "Ref to " << "A" << std::endl;
	} catch (std::exception &e)
	{}
	try {
		B &refB = dynamic_cast<B &>(p);
		(void)refB;
		std::cout << "Ref to " << "B" << std::endl;
	} catch (std::exception &e)
	{}
	try {
		C &refC = dynamic_cast<C &>(p);
		(void)refC;
		std::cout << "Ref to " << "C" << std::endl;
	} catch (std::exception &e)
	{}
}

int main()
{
	srand(time(0));
	Base *ptrA = nullptr;
	Base *ptrB = nullptr;
	Base *ptrC = nullptr;
	
	try {
		ptrA = generate();
		ptrB = generate();
		ptrC = generate();
		identify(ptrA);
		identify(ptrB);
		identify(ptrC);
		if (ptrA == nullptr)
			return (1);
		if (ptrB == nullptr)
			return (1);
		if (ptrC == nullptr)
			return (1);
		Base &refA = *ptrA;
		Base &refB = *ptrB;
		Base &refC = *ptrC;
		identify(refA);
		identify(refB);
		identify(refC);
	}
	catch (std::exception &e)
	{
		std::cout << "Error " << e.what() << std::endl;
	}
	delete ptrA;
	delete ptrB;
	delete ptrC;
}
