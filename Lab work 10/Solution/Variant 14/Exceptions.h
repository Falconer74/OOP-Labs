#pragma once
#include <string>
#include <iostream>
#include <exception>

class EmptyVectorException : public std::exception {
protected:
	std::string message;
public:
	EmptyVectorException(std::string msg);

	char const* what() const override;
};

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

std::ostream& operator << (std::ostream& out, const std::exception& e);