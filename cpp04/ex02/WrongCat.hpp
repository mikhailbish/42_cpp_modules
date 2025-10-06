#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat &other) = default;
		WrongCat& operator=(const WrongCat &other) = default;
		~WrongCat() = default;
		void makeSound() const;
};

#endif
