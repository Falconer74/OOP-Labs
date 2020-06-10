#pragma once
#include <iostream>
#define MAX_SIZE 10

class Vector
{
private:
	int size;
	int* elements;
public:
	Vector(int size);
	Vector(int size, int* values);

	int& operator[] (int index);
	void operator++ ();
	void operator++ (int notused);

	~Vector();

	friend std::ostream& operator << (std::ostream& out, Vector& v);
};

std::ostream& operator << (std::ostream& out, Vector& v);