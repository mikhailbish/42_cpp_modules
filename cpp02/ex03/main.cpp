#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Point getVector(Point a, Point b)
{
	return Point(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
}

Fixed getCrossProduct(Point vec1, Point vec2)
{
	return vec1.getX() * vec2.getY() - vec1.getY() * vec2.getX();
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed products[3];
	int positives = 0;
	int negatives = 0;
	Point AB = getVector(a, b);
	Point AX = getVector(a, point);
	Point BC = getVector(b, c);
	Point BX = getVector(b, point);
	Point CA = getVector(c, a);
	Point CX = getVector(c, point);

	products[0] = getCrossProduct(AB, AX);
	products[1] = getCrossProduct(BC, BX);
	products[2] = getCrossProduct(CA, CX);
	for (int i = 0; i < 3; i++)
	{
		if (products[i].toFloat() < 0)
			positives++;
		if (products[i].toFloat() > 0)
			negatives++;
	}
	if (positives == 3 || negatives == 3)
		return true;
	return false;
}


int main( void ) {
	struct {
		Point A = Point(0, 0);
		Point B = Point(0, 30);
		Point C = Point(30, 0);
	} t1;
	
	struct {
		Point A = Point(-1.18, -2.2);
		Point B = Point(-0.62, 1.24);
		Point C = Point(3.38, 1.7);
	} t2;
	struct {
		Point A = Point(-0, -0);
		Point B = Point(-5, 0);
		Point C = Point(-4, 6);
	} t3;
	
	
	{
		Point X(5, 5);
		Point Y(120, 120);
		Point Z(-1, 12);
		Point W(1, -12);
		Point V(0, 0);
		Point U(0, 1);

		std::cout << "\nTriangle one:\n" << t1.A << std::endl << t1.B << std::endl << t1.C << std::endl << std::endl;
		std::cout << X << (bsp(t1.A,t1.B,t1.C,X) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << Y << (bsp(t1.A,t1.B,t1.C,Y) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << Z << (bsp(t1.A,t1.B,t1.C,Z) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << W << (bsp(t1.A,t1.B,t1.C,W) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << V << (bsp(t1.A,t1.B,t1.C,V) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << U << (bsp(t1.A,t1.B,t1.C,U) ? " is inside the triangle" : " is outside the triangle") << std::endl;
	}

	{
		Point X(1.38, -1.48);
		Point Y(0.76, 0.5);
		Point Z(1, 3);
		Point W(-0.38, -1);
		Point V(-1.92, -0.76);

		std::cout << "\nTriangle two:\n" << t2.A << std::endl << t2.B << std::endl << t2.C << std::endl << std::endl;
		std::cout << X << (bsp(t2.A,t2.B,t2.C,X) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << Y << (bsp(t2.A,t2.B,t2.C,Y) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << Z << (bsp(t2.A,t2.B,t2.C,Z) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << W << (bsp(t2.A,t2.B,t2.C,W) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << V << (bsp(t2.A,t2.B,t2.C,V) ? " is inside the triangle" : " is outside the triangle") << std::endl;
	}

	{
		Point X(-2, 4);
		Point Y(-3.66, 3.54);
		Point Z(-1.1, 5.4);

		std::cout << "\nTriangle two:\n" << t3.A << std::endl << t3.B << std::endl << t3.C << std::endl << std::endl;
		std::cout << X << (bsp(t3.A,t3.B,t3.C,X) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << Y << (bsp(t3.A,t3.B,t3.C,Y) ? " is inside the triangle" : " is outside the triangle") << std::endl;
		std::cout << Z << (bsp(t3.A,t3.B,t3.C,Z) ? " is inside the triangle" : " is outside the triangle") << std::endl;
	}
	return 0;
}
