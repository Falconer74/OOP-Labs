#pragma once
#include <string>
#include <iostream>

class Line
{
private:
	float slope;
	float yIntercept;
public:
	enum Param {
		ParamYIntercept,
		ParamSlope
	};

	Line(float slope, float yIntersection);
	Line();

	void setSlope(float slope);
	void setYIntercept(float yIntersection);
	float getSlope() const;
	float getYIntercept() const;
	std::string toString() const;

	float& operator[] (Param param);
	std::string operator() ();
	void* operator new(size_t size);
	void* operator new[](size_t size);
	void operator delete(void* ptr);
	void operator delete[](void* ptr);

	~Line();
};

std::ostream& operator << (std::ostream& out, const Line &line);
std::istream& operator >> (std::istream& in, Line& line);