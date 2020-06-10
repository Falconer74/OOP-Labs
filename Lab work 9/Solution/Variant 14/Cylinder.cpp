#define _USE_MATH_DEFINES
#include "Cylinder.h"
#include <cmath>

Cylinder::Cylinder() : height(0), baseRadius(0)
{
}

Cylinder::Cylinder(float height, float radius) : height(height), baseRadius(radius)
{
}

float Cylinder::GetHeight() const
{
	return height;
}

float Cylinder::GetBaseRadius() const
{
	return baseRadius;
}

void Cylinder::SetHeight(float height)
{
	this->height = height;
}

void Cylinder::SetBaseRadius(float radius)
{
	this->baseRadius = radius;
}

float Cylinder::GetVolume() const
{
	return (M_PI * (baseRadius * baseRadius) * height);
}
