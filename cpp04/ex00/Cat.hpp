#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat &other) = default;
		Cat& operator=(const Cat &other) = default;
		~Cat() = default;
		void makeSound() const override;
};

#endif
