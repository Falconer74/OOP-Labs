#include "Exceptions.h"
#include <sstream>

ArrayMaxSizeException::ArrayMaxSizeException(std::string msg, int maxSize, int providedSize)
{
	std::stringstream sstream;
	sstream << msg << "\n\tMax size: " << maxSize << "\n\tProvided size:" << providedSize << std::endl;

	this->message = sstream.str();
	this->maxSize = maxSize;
	this->providedSize = providedSize;
}

NotInitializedVector::NotInitializedVector(std::string msg)
{
	message = msg;
}

EmptyVectorException::EmptyVectorException(std::string msg)
{
	message = msg;
}

OutOfBoundsException::OutOfBoundsException(std::string msg, int maxSize, int index)
{
	std::stringstream sstream;
	sstream << msg << "\n\tSize: " << maxSize << "\n\tProvided index:" << index << std::endl;

	this->message = sstream.str();
	this->maxSize = maxSize;
	this->invalidIndex = index;
}

char const* ArrayMaxSizeException::what() const
{
	return message.c_str();
}

char const* NotInitializedVector::what() const
{
	return message.c_str();
}

char const* OutOfBoundsException::what() const
{
	return message.c_str();
}

char const* EmptyVectorException::what() const
{
	return message.c_str();
}

std::ostream& operator<<(std::ostream& out, const std::exception& e)
{
	const char* str = e.what();
	out << e.what();

	return out;
}