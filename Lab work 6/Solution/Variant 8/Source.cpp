#include <iostream>
#include "Point.h"
#include "LineSegment.h"

using namespace std;

int main() {
	//Перегрузка оператора для создания массива объектов
	LineSegment *lineSegments = new LineSegment[2];
	for (int i = 0; i < 2; ++i) {
		cout << i + 1 << " line segment: " << endl;
		//Перегрузка оператора >>
		cin >> lineSegments[i];
	}
	cout << endl;
	for (int i = 0; i < 2; ++i) {
		cout << i + 1 << " line segment: " << endl;
		//Перегрузка оператора <<
		cout << lineSegments[i];
	}

	//Перегрузка оператора []
	cout << "Start point of second line segment: " << lineSegments[1]["start"] << endl;
	cout << "End point of first line segment: " << lineSegments[0]["end"] << endl;

	//Перегрузка оператора ()
	cout << "Length of first line segment: " << lineSegments[0]() << endl;
	cout << "Length of second line segment: " << lineSegments[1]() << endl;

	//Перегрузка оператора для удаления массива объектов
	delete[] lineSegments;

	return 0;
}