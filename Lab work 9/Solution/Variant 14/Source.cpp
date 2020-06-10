#include <iostream>
#include "Solid.h"
#include "Sphere.h"
#include "Cylinder.h"

using namespace std;

int main() {
	Solid* solid = new Sphere(4.5);
	cout << "Volume of sphere with radius 4.5: " << solid->GetVolume() << endl;
	delete solid;

	solid = new Cylinder(7, 2.5);
	cout << "Volume of cylinder with base radius 2.5 and height 7: " << solid->GetVolume() << endl;
	delete solid;

	return 0;
}