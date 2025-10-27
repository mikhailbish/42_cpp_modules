#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
	

int main()
{
	{
		Animal a;
		Dog d;
		Cat c;
		const Animal* meta = &a;
		const Animal* j = &d;
		const Animal* i = &c;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
	}
	{
		const WrongAnimal wa;
		const WrongAnimal* meta = &wa;
		const WrongCat wc;
		const WrongAnimal* i = &wc;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound(); //will output wrong animal sound!
		wc.makeSound(); //will output wrong cat sound!
	}
	return (0);
}
