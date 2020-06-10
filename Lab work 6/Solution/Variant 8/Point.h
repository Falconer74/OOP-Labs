#pragma once

#include <iostream>

class Point
{
public:
	float x;
	float y;
	static float getLength(Point p1, Point p2);
	Point();
	~Point();
};

std::ostream& operator << (std::ostream& out, const Point& p);
std::istream& operator >> (std::istream& in, Point& p);