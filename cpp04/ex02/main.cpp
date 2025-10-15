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

#define ANIMALNUM 10
int main()
{
	{
		Animal *animalArray[ANIMALNUM] = {nullptr};
		std::cout << "-----------------------------------------------------"<<std::endl;
		for (int i = 0; i < ANIMALNUM; i++)
		{
			if (i % 2 == 0)
				animalArray[i] = new(std::nothrow)Dog();
			else
				animalArray[i] = new(std::nothrow)Cat();
			if (animalArray[i] == nullptr)
				break;
			animalArray[i]->makeSound();
		}
		std::cout << "-----------------------------------------------------"<<std::endl;
		for (int i = 0; i < ANIMALNUM; i++)
		{
			delete animalArray[i];
		}
		
	}

	{
		Animal *animalArray[ANIMALNUM / 2] = {nullptr};
		Dog dogs[ANIMALNUM / 2];
		Cat cats[ANIMALNUM / 2];
		for (int i = 0; i < ANIMALNUM / 2; i++)
		{
			if (!checkBrain(cats[i]))
				return (1);
			if (!checkBrain(dogs[i]))
				return (1);
		}
		std::cout << "-----------------------------------------------------"<<std::endl;
		for (int i = 0; i < ANIMALNUM; i++)
		{
			if (i % 2 == 0)
				animalArray[i] = &dogs[i/2];
			else
				animalArray[i] = &cats[i/2];
		}
		(void)animalArray;
		for (int i = 0; i < ANIMALNUM; i++)
			animalArray[i]->makeSound();
		std::cout << "-----------------------------------------------------"<<std::endl;
	}

	Cat catA;
	if (!checkBrain(catA))
		return (1);
	Cat catB;
	if (!checkBrain(catB))
		return (1);
	catB = catA;
	catA.getBrain()->setIdea(0, "new idea");
	std::cout << "catB 0th idea " << catB.getBrain()->getIdea(0) << std::endl;
	if (!checkBrain(catB))
		return (1);
	return (0);
}
