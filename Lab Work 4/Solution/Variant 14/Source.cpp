#include <iostream>
#include "Date.h"

using namespace std;

int main() {
	//Default constructor
	Date date1 = Date();
	cout << "Default constructor: " << date1 << endl;


	//Constructor with parameters and initialization list
	Date date2 = Date(1999, 11, 11);
	cout << "Constructor with parameters and initialization list: " << date2 << endl;

	return 0;
}