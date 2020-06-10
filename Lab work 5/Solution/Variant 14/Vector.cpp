#define _USE_MATH_DEFINES
#include "Vector.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

void Vector::calculateLength()
{
	length = sqrt(x * x + y * y);
}

Vector::Vector(float x, float y) : x(x), y(y)
{
	calculateLength();
}

float Vector::getX() const
{
	return x;
}

float Vector::getY() const
{
	return y;
}

float Vector::getLength() const
{
	return length;
}

void Vector::setX(float x)
{
	this->x = x;

	calculateLength();
}

void Vector::setY(float y)
{
	this->y = y;

	calculateLength();
}

std::string Vector::toString() const
{
	std::ostringstream xStr, yStr;
	xStr.precision(2);
	yStr.precision(2);
	xStr << x;
	yStr << y;

	return "(" + xStr.str() + ";" + yStr.str() + ")";
}

float Vector::dotProduct(Vector v) const
{
	return x * v.getX() + y * v.getY();
}

float Vector::getAngle(Vector v) const
{
	return  acos(dotProduct(v) / (length * v.getLength())) * (180.0 / M_PI);
}

float Vector::dotProduct(const Vector& v1, const Vector& v2)
{
	return v1.getX() * v2.getX() + v1.getY() + v2.getY();
}

float Vector::getAngle(const Vector& v1, const Vector& v2)
{
	return acos(Vector::dotProduct(v1, v2) / v1.getLength() * v2.getLength()) * (180.0 / M_PI);
}

void Vector::operator=(Vector v)
{
	x = v.getX();
	y = v.getY();
}

Vector& operator--(Vector& v)
{
	v.x--;
	v.y--;

	v.calculateLength();

	return v;
}

float operator/(Vector v1, Vector v2)
{
	return v1.getAngle(v2);
}

std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
	out << vector.toString();
	return out;
}