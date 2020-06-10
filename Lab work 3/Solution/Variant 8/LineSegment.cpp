#include "LineSegment.h"

void LineSegment::calculateLength()
{
	length = Point::Distance(startPoint, endPoint);
}

LineSegment::LineSegment(Point startPoint, Point endPoint) : startPoint(startPoint), endPoint(endPoint)
{
	calculateLength();
}

Point LineSegment::getStartPoint() const
{
	return startPoint;
}

Point LineSegment::getEndPoint() const
{
	return endPoint;
}

float LineSegment::getLength() const
{
	return length;
}

void LineSegment::setStartPoint(Point p)
{
	startPoint = p;
}

void LineSegment::setEndPoint(Point p)
{
	endPoint = p;
}
