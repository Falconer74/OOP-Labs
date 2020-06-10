#include <iostream>
#include "Vector.h"
#include "Exceptions.h"
#include <ctime>

using namespace std;

void menu() {
	cout << "[0] - Exit\n";
	cout << "[1] - Create new vector and fill it with random numbers\n";
	cout << "[2] - Get element\n";
	cout << "[3] - Add random element to the start\n";
	cout << "[4] - Add random element to the end\n";
	cout << "[5] - Print vector\n";
}

int main() {
	srand(time(0));

	Vector* vector = nullptr;

	bool isExit = false;
	while (!isExit) {
		menu();
		int operation = 0;
		cout << "Select operation: ";
		cin >> operation;
		try {
			switch (operation) {
			case 0:
				isExit = true;
				break;
			case 1:
			{
				int size = 0;
				cout << "Enter vector size: ";
				cin >> size;
				if (vector != nullptr) {
					delete vector;
				}

				vector = new Vector(size);
			}
				break;
			case 2:
			{
				int index = 0;
				cout << "Enter element index: ";
				cin >> index;
				if (vector == nullptr) {
					throw NotInitializedVector("Vector is't initialized, initialize vector before using it");
				}

				cout << index << " element: " << (*vector)[index - 1] << endl;
			}
			break;
			case 3:
			{
				if (vector == nullptr) {
					throw NotInitializedVector("Vector is't initialized, initialize vector before using it");
				}

				++(*vector);
			}
			break;
			case 4:
			{
				if (vector == nullptr) {
					throw NotInitializedVector("Vector is't initialized, initialize vector before using it");
				}

				(*vector)++;
			}
			break;
			case 5:
			{
				if (vector == nullptr) {
					throw NotInitializedVector("Vector is't initialized, initialize vector before using it");
				}

				cout << "Vector elements:\n" << *vector << endl;
			}
			break;
			default:
				cout << "Wrong operation, try again" << endl;
			break;
			}
		}
		catch (Exception& e) {
			cout << e << endl;
		}

		system("pause");
		system("cls");
	}
	
}