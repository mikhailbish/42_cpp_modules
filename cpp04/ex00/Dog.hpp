#ifndef DOG_HPP
# define DOG_HPP 
#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog &other) = default;
		Dog& operator=(const Dog &other) = default;
		~Dog() = default;
		void makeSound() const override;
};

#endif
