#include <iostream>
#include "Man.h"
#include "Student.h"

using namespace std;

void print(Man& man) {
	cout << man << endl;
}

int main() {
	Man man = Man("Boris", 47, GenderEnum::Male, 83);
	Student student = Student("John Doe", 22, GenderEnum::Female, 63, 3);
	
	print(man);
	print(student);

	student.SetAge(99);
	cout << student << endl;

	return 0;
}