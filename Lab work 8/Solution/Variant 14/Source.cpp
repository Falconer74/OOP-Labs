#include <iostream>
#include "Pair.h"
#include "Long.h"

using namespace std;

void ResetValues(Pair& pair) {
	pair.SetFirst(0);
	pair.SetSecond(0);
}

int main() {
	Pair* p1 = new Pair(3, 2);
	Pair* p2 = new Pair(5, 6);
	Pair* result = p1->AddPairs(*p2);
	cout << "Pairs sum: " << *result << endl;

	delete p1;
	delete p2;
	delete result;

	p1 = new Long(3, 2);
	p2 = new Long(5, 6);
	//As a pair
	result = p1->AddPairs(*p2);

	cout << "Longs sum: " << *result << endl;

	//As a long
	Long* longResult = (Long*)result;

	Long* subtractResult = longResult->Subtract(*p1);
	cout << "Longs sum subtract first pair: " << *subtractResult << endl;

	delete result;

	Long* multiplicationResult = ((Long*)p1)->Multiply(*p2);

	cout << "Multiplication result: " << *multiplicationResult << endl;

	ResetValues(*multiplicationResult);

	cout << "Multiplication result after reset: " << *multiplicationResult << endl;

	delete p1;
	delete p2;
	delete subtractResult;
	delete multiplicationResult;

	return 0;
}