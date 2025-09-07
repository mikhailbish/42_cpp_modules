#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _bitlength = 8;
	public:
		Fixed(void);
		Fixed(Fixed &other);
		Fixed& operator=(const Fixed &f);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif
