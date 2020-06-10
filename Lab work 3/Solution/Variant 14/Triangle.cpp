#include "Triangle.h"
#include <cmath>

Triangle::Triangle(Point points[3])
{
	SetPoints(points);
}

void Triangle::SetPoints(Point points[3]) {
	this->points[0] = points[0];
	this->points[1] = points[1];
	this->points[2] = points[2];
	isPerimeterCached = false;
	isAreaCached = false;
	isSidesCached = false;
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

	if (!isSidesCached){
		cachedSides[0] = Point::Distance(points[0], points[1]);
		cachedSides[1] = Point::Distance(points[0], points[2]);
		cachedSides[2] = Point::Distance(points[1], points[2]);
		isSidesCached = true;
	}

	sides[0] = cachedSides[0];
	sides[1] = cachedSides[1];
	sides[2] = cachedSides[2];

	return sides;
}

double Triangle::GetPerimeter() {
	if (!isPerimeterCached) {
		double* sides = GetSides();
		cachedPerimeter = sides[0] + sides[1] + sides[2];
		isPerimeterCached = true;
	}

	return cachedPerimeter;
}

double Triangle::GetArea() {
	if (!isAreaCached) {
		double halfPerimeter = GetPerimeter() / 2;
		double* sides = GetSides();
		cachedArea = sqrt(halfPerimeter * (halfPerimeter - sides[0]) * (halfPerimeter - sides[1]) * (halfPerimeter - sides[2]));
		isAreaCached = true;
	}

	return cachedArea;
}