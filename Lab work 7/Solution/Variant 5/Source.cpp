#include <iostream>
#include "Cone.h"
#include "Logger.h"

using namespace std;

int menu() {
	cout << "[1] - Set cone parameters" << endl;
	cout << "[2] - Standard form" << endl;
	cout << "[3] - Check if point belong to cone" << endl;
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
	Cone* cone = nullptr;

	bool isExit = false;
	while (!isExit) {
		switch (menu()) {
		case 0:
			isExit = true;
			Logger::GetInstance().SaveLogs();
			break;
		case 1:
		{
			float a, b, c;
			cout << "Enter a: ";
			cin >> a;
			cout << "Enter b: ";
			cin >> b;
			cout << "Enter c: ";
			cin >> c;

			if (cone == nullptr) {
				cone = new Cone(a, b, c, "My cone");
			}
			else {
				cone->a = a;
				cone->b = b;
				cone->c = c;
			}
			Logger::GetInstance().AddRecord(*cone);
		}
		break;
		case 2:
		{
			if (cone == nullptr) {
				cout << "Cone has not been defined." << endl;
				ClearScreen();
				continue;
			}

			cout << (*cone) << endl;
		}
		break;
		case 3:
		{
			if (cone == nullptr) {
				cout << "Cone has not been defined." << endl;
				ClearScreen();
				continue;
			}

			float x, y, z;
			cout << "Enter point:\n";
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			cout << "z: ";
			cin >> z;
			if (cone->isBelongToCone(x, y, z)) {
				cout << "Point belong to cone" << endl;
			}
			else {
				cout << "Point doesn't belong to cone" << endl;
			}
		}
		break;
		default:
			cout << "Wrong operation, try again." << endl;
			break;
		}
		ClearScreen();
	}

	delete cone;

	return 0;
}