#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
	
int checkBrain(Cat &cat)
{
	if (cat.getBrain() != nullptr) 
	{
		return (cat.getBrain() != nullptr);
	}
	std::cout << "Brain alloc failed" << std::endl;
	return (cat.getBrain() != nullptr);
}

int checkBrain(Dog &cat)
{
	if (cat.getBrain() != nullptr) 
	{
		return (cat.getBrain() != nullptr);
	}
	std::cout << "Brain alloc failed" << std::endl;
	return (cat.getBrain() != nullptr);
}

int main()
{
	Cat catA;
	if (!checkBrain(catA))
		return (1);
	Cat catB;
	if (!checkBrain(catB))
		return (1);
	catB = catA;
	if (!checkBrain(catB))
		return (1);
	catA.makeSound();
	Dog dogA;
	if (!checkBrain(dogA))
		return (1);
	Dog dogB;
	if (!checkBrain(dogB))
		return (1);
	dogA = dogB;	
	if (!checkBrain(dogA))
		return (1);
	dogA.makeSound();
	return (0);
}
