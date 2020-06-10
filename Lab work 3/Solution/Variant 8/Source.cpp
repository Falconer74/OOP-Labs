#include "Point.h"
#include "LineSegment.h"
#include <iostream>

using namespace std;

int menu() {
	cout << "[1] - Set line segment" << endl;
	cout << "[2] - Show line segment length" << endl;
	cout << "[3] - Show start point" << endl;
	cout << "[4] - Show end point" << endl;
	cout << "[5] - Set start point" << endl;
	cout << "[6] - Set end point" << endl;
	cout << "[0] - Exit" << endl;
	int operation;
	cout << "Select operation: ";
	cin >> operation;
	return operation;
}

int main() {
	LineSegment *lineSegment = nullptr;

	bool isExit = false;
	while (!isExit) {
		switch (menu()) {
		case 0:
			isExit = true;
			break;
		case 1:
		{
			float x, y;
			
			cout << "Enter start point x: ";
			cin >> x;
			cout << "Enter start point y: ";
			cin >> y;
			Point startPoint(x, y);

			cout << "Enter end point x: ";
			cin >> x;
			cout << "Enter end point y: ";
			cin >> y;
			Point endPoint(x, y);

			if (lineSegment == nullptr) {
				lineSegment = new LineSegment(startPoint, endPoint);
			}
			else {
				lineSegment->setStartPoint(startPoint);
				lineSegment->setEndPoint(endPoint);
			}
		}
		break;
		case 2:
			if (lineSegment == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
			}
			else {
				cout << lineSegment->getLength() << endl;
			}
			break;
		case 3:
			if (lineSegment == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
			}
			else {
				lineSegment->getStartPoint().printPoint();
			}
			break;
		case 4:
			if (lineSegment == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
			}
			else {
				lineSegment->getEndPoint().printPoint();
			}
			break;
		case 5:
			if (lineSegment == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
			}
			else {
				float x, y;

				cout << "Enter start point x: ";
				cin >> x;
				cout << "Enter start point y: ";
				cin >> y;
				Point startPoint(x, y);

				lineSegment->setStartPoint(startPoint);
			}
			break;
		case 6:
			if (lineSegment == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
			}
			else {
				float x, y;

				cout << "Enter end point x: ";
				cin >> x;
				cout << "Enter end point y: ";
				cin >> y;
				Point endPoint(x, y);

				lineSegment->setEndPoint(endPoint);
			}
			break;
		default:
			cout << "Wrong operation, try again." << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	delete lineSegment;

	return 0;
}