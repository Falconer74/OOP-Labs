#pragma once
#include "Number.h"

class ComplexNumber : public Number
{
protected:
	float RealPart;
	float ImaginaryPart;
public:
	ComplexNumber(float real, float imaginary);

	float GetRealPart() const;
	float GetImaginaryPart() const;

	ComplexNumber operator+ (const ComplexNumber& num) const;
	ComplexNumber operator* (const ComplexNumber& num) const;

	virtual std::string toStr() const override;
};