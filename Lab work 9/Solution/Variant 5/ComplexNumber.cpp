#include "ComplexNumber.h"
#include <sstream>

ComplexNumber::ComplexNumber(float real, float imaginary) : RealPart(real), ImaginaryPart(imaginary) {}

float ComplexNumber::GetRealPart() const
{
	return RealPart;
}

float ComplexNumber::GetImaginaryPart() const
{
	return ImaginaryPart;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& num) const
{
	int real = RealPart + num.GetRealPart();
	int imaginary = ImaginaryPart + num.GetImaginaryPart();

	ComplexNumber result = ComplexNumber(real, imaginary);

	return result;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& num) const
{
	float real = RealPart * num.GetRealPart() + (-1 * ImaginaryPart * num.GetImaginaryPart());
	float imaginary = ImaginaryPart * num.GetRealPart() + RealPart * num.GetImaginaryPart();

	return ComplexNumber(real, imaginary);
}

std::string ComplexNumber::toStr() const
{
	std::stringstream sstream;
	sstream << "( " << RealPart << " ; " << ImaginaryPart << " )";

	return sstream.str();
}
