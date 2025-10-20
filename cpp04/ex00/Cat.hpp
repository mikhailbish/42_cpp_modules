#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat &other);
		Cat& operator=(const Cat &other);
		~Cat();
		void makeSound() const override;
};

#endif
