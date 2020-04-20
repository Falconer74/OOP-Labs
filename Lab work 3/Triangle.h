#pragma once

#include "Point.h"

class Triangle
{
private:
	Point points[3];
	
	double cachedSides[3];
	double cachedPerimeter;
	double cachedArea;

	bool isSidesCached;
	bool isPerimeterCached;
	bool isAreaCached;
public:
	Triangle(Point points[3]);

	void SetPoints(Point points[3]);
	Point* GetPoints() const;

	double* GetSides();
	double GetPerimeter();
	double GetArea();
};

