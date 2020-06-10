#pragma once
class Line
{
private:
	float slope;
	float yIntersection;
public:
	Line(float slope, float yIntersection);

	void setSlope(float slope);
	void setYIntersection(float yIntersection);
	float getSlope();
	float getYIntersection();

	bool operator|| (Line line);
	void operator= (Line line);
	friend float operator% (Line line1, Line line2);
};

float operator% (Line line1, Line line2);
void operator++ (Line& line);