#include "Point.h"
#include <cmath>

float Point::getLength(Point p1, Point p2)
{
	float vectorX = (p1.x - p2.x);
	float vectorY = (p1.y - p2.y);
	return sqrt(vectorX * vectorX + vectorY * vectorY);
}

Point::Point()
{
	x = 0;
	y = 0;
}

Point::~Point()
{
	std::cout << "Point destructor has been invoked" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "(" << p.x << ";" << p.y << ")";
	return out;
}

std::istream& operator>>(std::istream& in, Point& p)
{
	std::cout << "\nEnter x: ";
	in >> p.x;
	std::cout << "Enter y: ";
	in >> p.y;

	return in;
}
