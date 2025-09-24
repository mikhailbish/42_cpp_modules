#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point(void);
		Point(float x, float y);
		Point(const Point &other);
		Point& operator=(const Point &other) = delete;
		~Point(void);
		const Fixed getX(void) const;
		const Fixed getY(void) const;
		
};

std::ostream& operator<<(std::ostream& os, const Point& number);


#endif
