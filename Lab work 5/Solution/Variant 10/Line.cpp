#include "Line.h"
#define _USE_MATH_DEFINES
#include <cmath>

Line::Line(float slope, float yIntersection)
{
	this->slope = slope;
	this->yIntersection = yIntersection;
}

void Line::setSlope(float slope)
{
	this->slope = slope;
}

void Line::setYIntersection(float yIntersection)
{
	this->yIntersection = yIntersection;
}

float Line::getSlope()
{
	return slope;
}

float Line::getYIntersection()
{
	return yIntersection;
}

bool Line::operator||(Line line)
{
	if (line.getSlope() == slope) {
		return true;
	}
	return false;
}

void Line::operator=(Line line)
{
	slope = line.getSlope();
	yIntersection = line.getYIntersection();
}

float operator%(Line line1, Line line2)
{
	float denominator = 1 + line1.slope * line2.slope;
	if (denominator == 0) {
		return 0;
	}

	return atan(abs((line1.slope - line2.slope) / denominator)) * 180 / M_PI;
}

void operator++(Line& line)
{
	line.setYIntersection(line.getYIntersection() + 1);
}