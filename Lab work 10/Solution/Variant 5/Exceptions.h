#pragma once
#include <string>
#include <iostream>
#include <exception>

class ArrayMaxSizeException : public std::exception {
protected:
	std::string message;
	int maxSize;
	int providedSize;
public:
	ArrayMaxSizeException(std::string msg, int maxSize, int providedSize);

	char const* what() const override;
};

class OutOfBoundsException : public std::exception {
protected:
	std::string message;
	int maxSize;
	int invalidIndex;
public:
	OutOfBoundsException(std::string msg, int maxSize, int index);

	char const* what() const override;
};

class NotInitializedVector : public std::exception {
protected:
	std::string message;
public:
	NotInitializedVector(std::string msg);

	char const* what() const override;
};

class VaryVectorSizesException : public std::exception {
protected:
	std::string message;
	int size1, size2;
public:
	VaryVectorSizesException(std::string msg, int size1, int size2);

	char const* what() const override;
};

std::ostream& operator << (std::ostream& out, const std::exception& e);