#pragma once
#include "Number.h"

class Mixed : public Number
{
protected:
	int WholeNumber;
	int Numerator;
	int Denominator;
public:
	Mixed(int whole, int numerator, int denominator);

	int GetWholeNumber() const;
	int GetNumerator() const;
	int GetDenominator() const;

	void TakeWholePart();
	void Simplify();
	float ToDecimal() const;

	Mixed operator+ (const Mixed& num) const;

	virtual std::string toStr() const override;
};