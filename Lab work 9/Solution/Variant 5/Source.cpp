#include <iostream>
#include "Number.h"
#include "ComplexNumber.h"
#include "Mixed.h"

using namespace std;

int main() {
	Number* num1 = new ComplexNumber(3, -1);
	Number* num2 = new Mixed(3, 7, 13);

	cout << num1->toStr() << endl;
	cout << num2->toStr() << endl;

	return 0;
}