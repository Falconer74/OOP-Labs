#pragma once
#include "Point.h"
class LineSegment
{
private:
	Point start;
	Point end;
public:
	LineSegment();
	LineSegment(Point start, Point end);
	float getLength();

	Point& operator[] (const char* point);
	float operator() ();
	void* operator new (size_t size);
	void operator delete (void* ptr);
	void* operator new[] (size_t size);
	void operator delete[] (void* ptr);

	friend std::ostream& operator << (std::ostream& out, const LineSegment& p);
	friend std::istream& operator >> (std::istream& in, LineSegment& p);

	~LineSegment();
};

std::ostream& operator << (std::ostream& out, const LineSegment& p);
std::istream& operator >> (std::istream& in, LineSegment& p);