#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal &other) = default;
		Animal &operator=(const Animal &other) = default;
		virtual ~Animal() = default;
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
