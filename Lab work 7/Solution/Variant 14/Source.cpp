#include <iostream>
#include "Triangle.h"
#include "Point.h"
#include "Logger.h"

using namespace std;

int menu() {
	cout << "[1] - Set triangle points" << endl;
	cout << "[2] - Show side lenghts" << endl;
	cout << "[3] - Show triangle area" << endl;
	cout << "[4] - Show perimeter" << endl;
	cout << "[0] - Exit" << endl;
	int operation = 0;
	cout << "Select operation: ";
	cin >> operation;
	return operation;
}

inline void ClearScreen() {
	system("pause");
	system("cls");
}

int main() {
	Triangle* triangle = nullptr;

	bool isExit = false;
	while (!isExit) {
		switch (menu()) {
		case 0:
			isExit = true;
			Logger::GetInstance().SaveLogs();
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
				triangle = new Triangle(points, "MyTriangle");
			}
			else {
				triangle->SetPoints(points);
			}
			Logger::GetInstance().AddRecord(*triangle);
		}
		break;
		case 2:
		{
			if (triangle == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
				ClearScreen();
				continue;
			}

			double* sides = triangle->GetSides();
			for (int i = 0; i < 3; ++i) {
				cout << i + 1 << " side: " << sides[i] << endl;
			}
			delete[] sides;
		}
			break;
		case 3:
		{
			if (triangle == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
				ClearScreen();
				continue;
			}

			cout << "Triangle area: " << triangle->GetArea() << endl;
		}
			break;
		case 4:
		{
			if (triangle == nullptr) {
				cout << "Triangle has not been defined, set triangles points first." << endl;
				ClearScreen();
				continue;
			}

			cout << "Triangle perimeter: " << triangle->GetPerimeter() << endl;
		}
			break;
		default:
			cout << "Wrong operation, try again." << endl;
			break;
		}
		ClearScreen();
	}

	delete triangle;

	return 0;
}