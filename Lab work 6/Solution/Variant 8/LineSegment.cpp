#include "LineSegment.h"
#include "Point.h"

LineSegment::LineSegment()
{
}

LineSegment::LineSegment(Point start, Point end)
{
	this->start = start;
	this->end = end;
}

float LineSegment::getLength()
{
	return Point::getLength(start, end);
}

Point& LineSegment::operator[](const char* point)
{
	if (point == "start") {
		return start;
	}
	else if (point == "end") {
		return end;
	}
}

float LineSegment::operator()()
{
	return getLength();
}

std::ostream& operator<<(std::ostream& out, const LineSegment& p)
{
	out << "start point: " << p.start << "   end point:" << p.end << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, LineSegment& p)
{
	Point start, end;
	std::cout << "Start point: ";
	in >> start;
	std::cout << "End point: ";
	in >> end;

	p["start"] = start;
	p["end"] = end;

	return in;
}

void* LineSegment::operator new(size_t size)
{
	std::cout << "operator new has been invoked." << std::endl;
	LineSegment* lineSegment = new LineSegment();
	return lineSegment;
}

void LineSegment::operator delete(void* ptr)
{
	std::cout << "operator delete has been invoked." << std::endl;
	::operator delete(ptr);
}

void* LineSegment::operator new[](size_t size)
{
	std::cout << "operator new[] has been invoked." << std::endl;
	void* ptr = malloc(size);
	return ptr;
}

void LineSegment::operator delete[](void* ptr)
{
	std::cout << "operator delete[] has been invoked." << std::endl;
	::operator delete[](ptr);
}

LineSegment::~LineSegment()
{
	std::cout << "Destructor has been invoked." << std::endl;
}
