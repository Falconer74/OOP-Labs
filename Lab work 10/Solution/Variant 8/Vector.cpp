#include "Vector.h"
#include "Exceptions.h"

Vector::Vector(int size)
{
	if (size > MAX_SIZE) {
		throw ArrayMaxSizeException("Provided size in method Vector::Vector(int) is bigger than max size", MAX_SIZE, size);
	}
	this->size = size;
	elements = new int[size];

	for (int i = 0; i < size; ++i) {
		elements[i] = rand() % 100;
	}
}

Vector::Vector(int size, int* values)
{
	if (size > MAX_SIZE) {
		throw ArrayMaxSizeException("Provided size in method Vector::Vector(int, int*) is bigger than max size", MAX_SIZE, size);
	}
	this->size = size;
	elements = new int[size];

	for (int i = 0; i < size; ++i) {
		elements[i] = values[i];
	}
}

int& Vector::operator[](int index)
{
	if (index < 0) {
		throw OutOfBoundsException("Provided index in method Vector::operator[] is less than 0", size, index);
	}
	else if (index >= size) {
		throw OutOfBoundsException("Provided index in method Vector::operator[] is bigger than ", size, index);
	}

	return elements[index];
}

void Vector::operator++(int notused)
{
	if (size + 1 > MAX_SIZE) {
		throw ArrayMaxSizeException("Can't expand array in method Vector::operator++() more than max size", MAX_SIZE, size + 1);
	}

	++size;
	int* tmp = new int[size];
	for (int i = 0; i < size - 1; ++i) {
		tmp[i] = elements[i];
	}
	tmp[size - 1] = rand() % 100;

	delete[] elements;
	elements = tmp;
}

void Vector::operator++()
{
	if (size + 1 > MAX_SIZE) {
		throw ArrayMaxSizeException("Can't expand array in method Vector::operator++() more than max size", MAX_SIZE, size + 1);
	}

	++size;
	int* tmp = new int[size];
	for (int i = 1; i < size; ++i) {
		tmp[i] = elements[i - 1];
	}

	tmp[0] = rand() % 100;

	delete[] elements;
	elements = tmp;
}

Vector::~Vector() {
	delete[] elements;
}

std::ostream& operator<<(std::ostream& out, Vector& v)
{
	for (int i = 0; i < v.size; ++i) {
		out << v.elements[i] << "\t";
	}

	return out;
}