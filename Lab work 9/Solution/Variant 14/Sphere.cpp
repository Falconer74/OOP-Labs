#define _USE_MATH_DEFINES
#include "Sphere.h"
#include <cmath>

Sphere::Sphere() : radius(0)
{
}

Sphere::Sphere(float radius) : radius(radius)
{
}

float Sphere::GetRadius() const
{
	return radius;
}

void Sphere::SetRadius(float radius)
{
	this->radius = radius;
}

float Sphere::GetVolume() const
{
	return ((4 / 3) * (float)M_PI * (radius * radius * radius));
}
