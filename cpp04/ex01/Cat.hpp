#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *head;
	public:
		Cat();
		Cat(Cat &other) = default;
		Cat& operator=(const Cat &other) = default;
		~Cat();
		void makeSound() const override;
		Brain *getBrain() const;
};

#endif
