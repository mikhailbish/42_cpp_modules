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

	{
		Animal animalArray[10];
		std::cout << "-----------------------------------------------------"<<std::endl;
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				animalArray[i] = Dog();
			else
				animalArray[i] = Cat();
			animalArray[i].makeSound();
		}
		std::cout << "-----------------------------------------------------"<<std::endl;
	}

/*
	{
		Animal *animalArray[10];
		std::cout << "-----------------------------------------------------"<<std::endl;
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				animalArray[i] = new Dog();
			else
				animalArray[i] = new Cat();
			animalArray[i].makeSound();
		}
		std::cout << "-----------------------------------------------------"<<std::endl;
		for (int i = 0; i < 10; i++)
		{
			delete animalArray[i];
		}
		
	}
*/
/*
	Cat catA;
	if (!checkBrain(catA))
		return (1);
	Cat catB;
	if (!checkBrain(catB))
		return (1);
	catB = catA;
	if (!checkBrain(catB))
		return (1);
	*/
	return (0);
}
