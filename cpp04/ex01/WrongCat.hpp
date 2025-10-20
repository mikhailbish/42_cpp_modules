#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat &other);
		WrongCat& operator=(const WrongCat &other);
		~WrongCat();
		void makeSound() const;
};

#endif
