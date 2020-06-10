#include <iostream>
#include "Vector.h"
#include "Exceptions.h"
#include <ctime>

using namespace std;

void menu() {
	cout << "[0] - Exit\n";
	cout << "[1] - Create new vector and fill it with random numbers\n";
	cout << "[2] - Get element\n";
	cout << "[3] - Get vector size\n";
	cout << "[4] - Raise vector to the 2 power\n";
	cout << "[5] - Check +n operator\n";
	cout << "[6] - Print vector\n";
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
				if (vector == nullptr) {
					throw NotInitializedVector("Vector is't initialized, initialize vector before using it");
				}
				cout << "Number of elements in vector: " << (*vector)() << endl;
				break;
			case 4:
			{
				if (vector == nullptr) {
					throw NotInitializedVector("Vector is't initialized, initialize vector before using it");
				}
				
				cout << (*vector) * (*vector);
			}
			break;
			case 5:
			{
				int n = 0;
				cout << "Enter element index: ";
				cin >> n;
				if (vector == nullptr) {
					throw NotInitializedVector("Vector is't initialized, initialize vector before using it");
				}

				cout << n << " element: " << (*vector)[n - 1] << endl;
			}
			break;
			case 6:
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
		catch (const std::exception& e) {
			cout << e << endl;
		}

		system("pause");
		system("cls");
	}

}