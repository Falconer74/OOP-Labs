#include "Point.h"
#include <cmath>

double Point::Distance(Point p) const {
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

double Point::Distance(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}