#include "Line.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <sstream>

Line::Line(float slope, float yIntersection)
{
	this->slope = slope;
	this->yIntercept = yIntersection;
}

Line::Line()
{
	slope = 0;
	yIntercept = 0;
}

void Line::setSlope(float slope)
{
	this->slope = slope;
}

void Line::setYIntercept(float yIntersection)
{
	this->yIntercept = yIntersection;
}

float Line::getSlope() const
{
	return slope;
}

float Line::getYIntercept() const
{
	return yIntercept;
}

std::string Line::toString() const
{
	std::stringstream ss;
	ss << slope << " * x + " << yIntercept;
	return ss.str();
}

float& Line::operator[](Param param)
{
	switch (param) {
	case Param::ParamSlope:
		return slope;
		break;
	case Param::ParamYIntercept:
		return yIntercept;
		break;
	}
}

std::string Line::operator()()
{
	return toString();
}

void* Line::operator new(size_t size)
{
	void* ptr = malloc(size);
	if (ptr == nullptr) {
		throw std::bad_alloc();
	}
	std::cout << "operator new has benn invoked, " << size << " bytes of memory has been allocated." << std::endl;
	return ptr;
}

void* Line::operator new[](size_t size)
{
	void* ptr = malloc(size);
	if (ptr == nullptr) {
		throw std::bad_alloc();
	}
	std::cout << "operator new[] has benn invoked, " << size << " bytes of memory has been allocated." << std::endl;
	return ptr;
}

void Line::operator delete(void* ptr)
{
	free(ptr);
	std::cout << "operator delete has benn invoked" << std::endl;
}

void Line::operator delete[](void* ptr)
{
	free(ptr);
	std::cout << "operator delete[] has benn invoked" << std::endl;
}

Line::~Line()
{
	std::cout << "Destructor has been invoked." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Line& line)
{
	std::cout << line.toString();

	return out;
}

std::istream& operator>>(std::istream& in, Line& line)
{
	float slope, yIntercept;
	std::cout << "Enter slope: ";
	std::cin >> slope;
	std::cout << "Enter y intercept: ";
	std::cin >> yIntercept;

	line.setSlope(slope);
	line.setYIntercept(yIntercept);

	return in;
}