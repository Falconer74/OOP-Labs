#pragma once

class Point
{
public:
	double x, y;
	double Distance(Point p) const;
	static double Distance(Point p1, Point p2);
};