#pragma once
#include <string>
#include <iostream>

class Exception {
protected:
	std::string message;
public:
	Exception(std::string msg);

	std::string GetMessage() const;
	virtual std::string ToString() const;
};

class OutOfBoundsException : public Exception {
protected:
	int maxSize;
	int invalidIndex;
public:
	OutOfBoundsException(std::string message, int maxSize, int index);

	std::string ToString() const override;
};

class ArrayMaxSizeException : public Exception {
protected:
	int maxSize;
	int providedSize;
public:
	ArrayMaxSizeException(std::string, int maxSize, int providedSize);

	std::string ToString() const override;
};

class NotInitializedVector : public Exception {
public:
	NotInitializedVector(std::string message);

	std::string ToString() const override;
};

std::ostream& operator << (std::ostream& out, const Exception& e);