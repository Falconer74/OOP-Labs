#pragma once
class Point
{
public:
	float x, y;
	float Distance(Point p) const;
	Point(float x, float y);
	static float Distance(Point p1, Point p2);
	void printPoint();
};