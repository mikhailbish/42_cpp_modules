#include "Point.hpp"

Point::Point(void) : x(), y()
{
//	this->x = Fixed();
//	this->y = Fixed();
}

Point::Point(const float xParam, const float yParam) : x(xParam), y(yParam)
{
//	this->x = Fixed(xParam);
//	this->y = Fixed(yParam);
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
	(void)other;
//	this->x = other.x;
//	this->y = other.y;
}

Point::~Point(void)
{

}

const Fixed Point::getX(void) const
{
	return (this->x);
}

const Fixed Point::getY(void) const
{
	return (this->y);
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << "Point x: " << point.getX() << " y: " << point.getY();
	return os;
}
