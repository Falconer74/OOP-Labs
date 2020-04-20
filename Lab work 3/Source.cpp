#include <iostream>
#include "Triangle.h"
#include "Point.h"

using namespace std;

int menu() {
	cout << "[1] - Set triangle points" << endl;
	cout << "[2] - Show side lenghts" << endl;
	cout << "[3] - Show triangle area" << endl;
	cout << "[4] - Show perimeter" << endl;
	cout << "[0] - Exit" << endl;
	int operation;
	cout << "Select operation: ";
	cin >> operation;
	return operation;
}

int main() {
	Triangle* triangle = nullptr;

	bool isExit = false;
	while (!isExit) {
		switch (menu()) {
		case 0:
			isExit = true;
			break;
		case 1:
		{
			Point points[3];
			for (int i = 0; i < 3; ++i) {
				cout << i + 1 << " point: " << endl;
				cout << "Enter x: ";
				cin >> points[i].x;
				cout << "Enter y: ";
				cin >> points[i].y;
			}
			if (triangle == nullptr) {
				triangle = new Triangle(points);
			}
			else {
				triangle->SetPoints(points);
			}
		}
			break;
		case 2:
		
			if (triangle == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
			}
			else {
				double* sides = triangle->GetSides();
				for (int i = 0; i < 3; ++i) {
					cout << i + 1 << " side: " << sides[i] << endl;
				}
				delete[] sides;
			}
			break;
		case 3:
			if (triangle == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
			}
			else {
				cout << "Triangle area: " << triangle->GetArea() << endl;
			}
			break;
		case 4:
			if (triangle == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
			}
			else {
				cout << "Triangle perimeter: " << triangle->GetPerimeter() << endl;
			}
			break;
		default:
			cout << "Wrong operation, try again." << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	delete triangle;

	return 0;
}