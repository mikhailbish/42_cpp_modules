#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal &other) = default;
		WrongAnimal &operator=(const WrongAnimal &other) = default;
		virtual ~WrongAnimal() = default;
		void makeSound() const;
		std::string getType() const;
};

#endif
