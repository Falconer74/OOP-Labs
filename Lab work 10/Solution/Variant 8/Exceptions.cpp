#include "..\LabWork10\Exceptions.h"
#include "Exceptions.h"
#include <sstream>

Exception::Exception(std::string msg)
{
	message = msg;
}

std::string Exception::GetMessage() const
{
	return message;
}

std::string Exception::ToString() const
{
	return message;
}

OutOfBoundsException::OutOfBoundsException(std::string msg, int maxSize, int index) : Exception(msg)
{
	this->maxSize = maxSize;
	this->invalidIndex = index;
}

std::string OutOfBoundsException::ToString() const
{
	std::stringstream sstream;
	sstream << message << "\Size: " << maxSize << "\nProvided index:" << invalidIndex << std::endl;
	return sstream.str();
}

ArrayMaxSizeException::ArrayMaxSizeException(std::string msg, int maxSize, int providedSize) : Exception(msg)
{
	this->maxSize = maxSize;
	this->providedSize = providedSize;
}

std::string ArrayMaxSizeException::ToString() const
{
	std::stringstream sstream;
	sstream << message << "\nMax size: " << maxSize << "\nProvided size: " << providedSize << std::endl;
	return sstream.str();
}

std::ostream& operator<<(std::ostream& out, const Exception& e)
{
	out << e.ToString();

	return out;
}

NotInitializedVector::NotInitializedVector(std::string msg) : Exception(msg)
{
}

std::string NotInitializedVector::ToString() const
{
	return message;
}
