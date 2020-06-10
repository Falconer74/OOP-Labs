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

Vector::Vector(const Vector& other) : size(other())
{	
	elements = new int[size];
	for (int i = 0; i < size; ++i) {
		elements[i] = other[i];
	}
}

int& Vector::operator[](int index) const
{
	if (index < 0) {
		throw OutOfBoundsException("Provided index in method Vector::operator[] is less than 0", size, index);
	}
	else if (index >= size) {
		throw OutOfBoundsException("Provided index in method Vector::operator[] is bigger than ", size, index);
	}

	return elements[index];
}

int Vector::operator()() const
{
	return size;
}

Vector Vector::operator*(Vector v) const
{
	if (v() != size) {
		throw VaryVectorSizesException("You cannot multiply vectors with different size", v(), size);
	}

	int* elems = new int[size];
	for (int i = 0; i < size; i++)
	{
		elems[i] = elements[i] * v[i];
	}

	Vector newVector = Vector(size, elems);

	delete[] elems;

	return newVector;
}

int Vector::operator+(int n) const
{
	return elements[n];
}

Vector::~Vector() {
	delete[] elements;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	for (int i = 0; i < v.size; ++i) {
		out << v.elements[i] << "\t";
	}

	return out;
}