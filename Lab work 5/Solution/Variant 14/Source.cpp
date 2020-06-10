#include <iostream>
#include "Vector.h"
#include <string>

using namespace std;

int main() {
	float x, y;
	cout << "First vector:" << endl;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	Vector firstVector(x, y);
	cout << "Second vector:" << endl;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	Vector secondVector(x, y);

	cout << "First vector: " << firstVector << endl;
	cout << "Second vector: " << secondVector << endl;

	cout << firstVector << " / " << secondVector << " = " << firstVector / secondVector << endl;
	cout << "--" << firstVector << " = ";
	cout << (--firstVector) << endl;
	cout << firstVector << " = " << secondVector << endl;
	firstVector = secondVector;
	cout << "First vector: " << firstVector << endl;
	cout << "Second vector: " << secondVector << endl;

	return 0;
}