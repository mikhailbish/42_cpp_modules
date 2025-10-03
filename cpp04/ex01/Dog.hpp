#ifndef DOG_HPP
# define DOG_HPP 
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *head;

	public:
		Dog();
		Dog(Dog &other) = default;
		Dog& operator=(const Dog &other) = default;
		~Dog();
		void makeSound() const override;
		Brain *getBrain() const;
};

#endif
