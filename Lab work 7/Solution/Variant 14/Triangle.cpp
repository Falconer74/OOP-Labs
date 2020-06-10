#include "Triangle.h"
#include <cmath>

void Triangle::evaluateProperties()
{
	Sides[0] = Point::Distance(points[0], points[1]);
	Sides[1] = Point::Distance(points[0], points[2]);
	Sides[2] = Point::Distance(points[1], points[2]);

	Perimeter = Sides[0] + Sides[1] + Sides[2];

	double halfPerimeter = Perimeter / 2;
	Area = sqrt(halfPerimeter * (halfPerimeter - Sides[0]) * (halfPerimeter - Sides[1]) * (halfPerimeter - Sides[2]));
}

Triangle::Triangle(Point points[3], std::string objectName)
{
	SetPoints(points);
	this->objectName = objectName;
}

void Triangle::SetPoints(Point points[3]) {
	this->points[0] = points[0];
	this->points[1] = points[1];
	this->points[2] = points[2];

	evaluateProperties();
}

Point* Triangle::GetPoints() const {
	Point* pts = new Point[3];
	pts[0] = points[0];
	pts[1] = points[1];
	pts[2] = points[2];

	return pts;
}

double* Triangle::GetSides() {
	double* sides = new double[3];
	sides[0] = Sides[0];
	sides[1] = Sides[1];
	sides[2] = Sides[2];

	return sides;
}

double Triangle::GetPerimeter() {
	return Perimeter;
}

double Triangle::GetArea() {
	return Area;
}

std::string Triangle::GetObjectName()
{
	return objectName;
}
