#pragma once
#include "Point.h"

class LineSegment
{
private:
	Point startPoint;
	Point endPoint;
	float length;
	void calculateLength();
public:
	LineSegment(Point startPoint, Point endPoint);

	Point getStartPoint() const;
	Point getEndPoint() const;
	float getLength() const;

	void setStartPoint(Point p);
	void setEndPoint(Point p);
};