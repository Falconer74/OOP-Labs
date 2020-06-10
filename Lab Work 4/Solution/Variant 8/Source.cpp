#include "Vector.h"
#include <iostream>

using namespace std;

int menu() {
	cout << "[1] - Print vectors" << endl;
	cout << "[2] - Get Length" << endl;
	cout << "[3] - Take dot product" << endl;
	cout << "[4] - Find angle" << endl;
	cout << "[5] - Edit vector" << endl;
	cout << "[0] - Exit" << endl;
	int operation;
	cout << "Select operation: ";
	cin >> operation;
	return operation;
}

void printVectors(Vector** vectors, int size) {
	for (int i = 0; i < size; ++i) {
		cout << "[" << i + 1 << "] ";
		vectors[i]->print();
	}
}

int main() {
	int size;
	cout << "Enter vectors array size: ";
	cin >> size;

	Vector** vectors = new Vector * [size];
	for (int i = 0; i < size; ++i) {
		float x, y;
		cout << "Vector " << i + 1 << endl;
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter y: ";
		cin >> y;
		
		vectors[i] = new Vector(x, y);
	}
	system("cls");

	bool isExit = false;
	while (!isExit) {
		switch (menu()) {
		case 0:
			isExit = true;
			break;
		case 1:
			printVectors(vectors, size);
			break;
		case 2:
		{
			printVectors(vectors, size);
			int index;
			cout << "Select vector: ";
			cin >> index;
			cout << "Length: " << vectors[index - 1]->getLength();
		}
			break;
		case 3:
		{
			printVectors(vectors, size);
			int index1, index2;
			cout << "Select first vector: ";
			cin >> index1;
			cout << "Select second vector: ";
			cin >> index2;
			cout << "Dot product: " << Vector::dotProduct(*vectors[index1 - 1], *vectors[index2 - 1]) << endl;
		}
			break;
		case 4:
		{
			printVectors(vectors, size);
			int index1, index2;
			cout << "Select first vector: ";
			cin >> index1;
			cout << "Select second vector: ";
			cin >> index2;
			cout << "Angle: " << Vector::dotProduct(*vectors[index1 - 1], *vectors[index2 - 1]) << endl;
		}
			break;
		case 5:
		{
			printVectors(vectors, size);
			int index;
			cout << "Select vector: ";
			cin >> index;
			float x, y;
			cout << "Enter new x: ";
			cin >> x;
			cout << "Enter new y: ";
			cin >> y;
			vectors[index - 1]->setX(x);
			vectors[index - 1]->setY(y);
		}
			break;
		default:
			cout << "Wrong operation, try again." << endl;
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
	}

	for (int i = 0; i < size; ++i) {
		delete vectors[i];
	}

	delete[] vectors;

	return 0;
}