#include <iostream>
#include "Fraction.h";

using namespace std;

int menu() {
	cout << "Select operation: " << endl;
	cout << "[1] - Print fractions" << endl;
	cout << "[2] - ==" << endl;
	cout << "[3] - !=" << endl;
	cout << "[4] - +" << endl;
	cout << "[5] - *" << endl;
	cout << "[6] - --" << endl;
	cout << "[0] - Exit" << endl;
	int operation;
	cout << "Select operation: ";
	cin >> operation;
	return operation;
}

void printFractions(Fraction** fractions, int size) {
	for (int i = 0; i < size; ++i) {
		cout << "[" << i + 1 << "] ";
		cout << *fractions[i] << endl;
	}
}

int main() {
	Fraction** fractions;
	int size;
	cout << "Enter number of fractions: ";
	cin >> size;
	fractions = new Fraction*[size];
	for (int i = 0; i < size; ++i) {
		float numerator, denominator;
		cout << "Fraction " << i + 1 << endl;
		cout << "Enter numerator: ";
		cin >> numerator;
		cout << "Enter denominator: ";
		cin >> denominator;

		fractions[i] = new Fraction(numerator, denominator);
	}
	system("cls");

	bool isExit = false;
	while (!isExit) {
		switch (menu()) {
		case 0:
			isExit = true;
			break;
		case 1:
			printFractions(fractions, size);
			break;
		case 2:
		{
			printFractions(fractions, size);
			int index1, index2;
			cout << "Select first fraction: ";
			cin >> index1;
			cout << "Select second fraction: ";
			cin >> index2;
			cout << *fractions[index1 - 1] << " == " << *fractions[index2 - 1] << " - ";
			if (*fractions[index1 - 1] == *fractions[index2 - 1])
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		break;
		case 3:
		{
			printFractions(fractions, size);
			int index1, index2;
			cout << "Select first fraction: ";
			cin >> index1;
			cout << "Select second fraction: ";
			cin >> index2;
			cout << *fractions[index1 - 1] << " != " << *fractions[index2 - 1] << " - ";
			if (*fractions[index1 - 1] != *fractions[index2 - 1])
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		break;
		case 4:
		{
			printFractions(fractions, size);
			int index1, index2;
			cout << "Select first fraction: ";
			cin >> index1;
			cout << "Select second fraction: ";
			cin >> index2;
			cout << *fractions[index1 - 1] << " + " << *fractions[index2 - 1] << " = " << (*fractions[index1 - 1]) + (*fractions[index2 - 1]);
		}
		break;
		case 5:
		{
			printFractions(fractions, size);
			int index1, index2;
			cout << "Select first fraction: ";
			cin >> index1;
			cout << "Select second fraction: ";
			cin >> index2;
			cout << *fractions[index1 - 1] << " * " << *fractions[index2 - 1] << " = " << (*fractions[index1 - 1]) * (*fractions[index2 - 1]);
		}
		break;
		case 6:
			printFractions(fractions, size);
			int index;
			cout << "Select first fraction: ";
			cin >> index;
			cout << *fractions[index - 1] << " - ";
			cout << --(*fractions[index - 1]) << endl;
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
		delete fractions[i];
	}

	delete[] fractions;

	return 0;
}