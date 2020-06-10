#include <iostream>
#include "Line.h"

using namespace std;

int main() {
	//operator new
	Line* line = new Line(3.5, 0.7);
	//operator new[]
	Line* lines = new Line[3];
	for (int i = 0; i < 3; ++i) {
		//operator >>
		cin >> lines[i];
	}
	cout << endl;

	//operator ()
	cout << (*line)() << endl;
	//operator []
	cout << "Y intercept: " << (*line)[Line::Param::ParamYIntercept] << endl << endl;

	for (int i = 0; i < 3; ++i) {
		//operator <<
		cout << i + 1 << " line: " << lines[i] << endl;
	}

	cout << endl << endl;

	//operator delete
	delete line;
	//operator delete[]
	delete[] lines;

	return 0;
}