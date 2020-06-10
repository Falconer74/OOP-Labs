#include <iostream>
#include "Line.h"

using namespace std;

int main() {
	Line line1 = Line(2, -1);
	Line line2 = Line(-3, 1);

	cout << "First line: y = " << line1.getSlope() << "x " << line1.getYIntersection() << endl;
	cout << "Second line: y = " << line2.getSlope() << "x " << line2.getYIntersection() << endl;

	cout << "Is paralel: " << (line1 || line2) << endl;
	cout << "Angle between: " << (line1 % line2) << endl;

	line2 = line1;
	++line1;

	cout << "First line: y = " << line1.getSlope() << "x " << line1.getYIntersection() << endl;
	cout << "Second line: y = " << line2.getSlope() << "x " << line2.getYIntersection() << endl;
	return 0;
}