#pragma once

#include "Point.h"
#include <string>

class Triangle
{
private:
	Point points[3];

	std::string objectName;

	double Sides[3];
	double Perimeter;
	double Area;

	void evaluateProperties();
public:
	Triangle(Point points[3], std::string objectName);

	void SetPoints(Point points[3]);
	Point* GetPoints() const;

	double* GetSides();
	double GetPerimeter();
	double GetArea();
	std::string GetObjectName();
};