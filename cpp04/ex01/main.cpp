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

void animalsProcess(Animal **animals)
{
	try {
		for (int i = 0; i < 10; i++)
			animals[i]->makeSound();
	}
	catch (std::exception &e)
	{
		std::cout << "Error: "  << e.what() << std::endl;
	}
}

int main()
{
/*
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
	{
		Animal *animalPtrArray[10];
		Animal animalArray[10];
		(void)animalPtrArray;
//		Dog dogs[5];
//		Cat cats[5];
		for (int i = 0; i < 10; i++)
		{
			animalPtrArray[i] = &animalArray[i];
		}
//		animalPtrArray = (Animal **)&animalArray;
		std::cout << "-----------------------------------------------------"<<std::endl;
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				*animalPtrArray[i] = Dog();
			else
				*animalPtrArray[i] = Cat();
	//		animalArray[i].makeSound();
		}
		animalsProcess(animalPtrArray);
//		for (int i = 0; i < 5; i++)
//		{
//			dogs[i].~Dog();
//			cats[i].~Cat();
//		}
//		for (int i = 0; i < 10; i++)
//			animalArray[i].makeSound();
		std::cout << "-----------------------------------------------------"<<std::endl;
	}
*/
/*
	{
	//	Animal **animalPtrArray;
		Animal *animalArray[10];
//		Animal animals[10];
		for (int i = 0; i < 10; i++)
		{
//			animalArray[i] = &animals[i];
		}
//		(void)animalPtrArray;
		Dog dogs[5];
		Cat cats[5];
//		animalPtrArray = (Animal **)&animalArray;
		std::cout << "-----------------------------------------------------"<<std::endl;
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				animalArray[i] = &dogs[i/2];
			else
				animalArray[i] = &cats[i/2];
		}
		for (int i = 0; i < 5; i++)
		{
//			dogs[i].~Animal();
//			cats[i].~Animal();
		}
		(void)animalArray;
		for (int i = 0; i < 10; i++)
			animalArray[i]->makeSound();
		std::cout << "-----------------------------------------------------"<<std::endl;
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
