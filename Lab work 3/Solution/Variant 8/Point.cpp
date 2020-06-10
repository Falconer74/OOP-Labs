#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}

float Point::Distance(Point p) const {
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

float Point::Distance(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void Point::printPoint()
{
	std::cout << "(" << x << ";" << y << ")" << std::endl;
}
