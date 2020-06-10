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
	Vector(const Vector& other);

	int& operator[] (int index) const;
	int operator()() const;
	Vector operator*(Vector v) const;
	int operator+ (int n) const;

	~Vector();

	friend std::ostream& operator << (std::ostream& out, const Vector& v);
};

std::ostream& operator << (std::ostream& out, const Vector& v);