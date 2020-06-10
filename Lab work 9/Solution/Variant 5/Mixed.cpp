#include "Mixed.h"
#include <sstream>

Mixed::Mixed(int whole, int numerator, int denominator) : WholeNumber(whole), Numerator(numerator), Denominator(denominator) {}

int Mixed::GetWholeNumber() const
{
	return WholeNumber;
}

int Mixed::GetNumerator() const
{
	return Numerator;
}

int Mixed::GetDenominator() const
{
	return Denominator;
}

void Mixed::TakeWholePart()
{
	WholeNumber += Numerator / Denominator;
	Numerator -= (Numerator / Denominator) * Denominator;
}

void Mixed::Simplify()
{
	bool isSimplified = false;
	while (!isSimplified) {
		int min;
		if (Numerator < Denominator)
			min = Numerator;
		else
			min = Denominator;

		for (int i = 2; i <= min; ++i) {
			if (Numerator % i == 0 && Denominator % i == 0) {
				Numerator /= i;
				Denominator /= i;
				break;
			}
			isSimplified = true;
		}
	}
}

float Mixed::ToDecimal() const
{
	return (float)WholeNumber + ((float)Numerator / (float)Denominator);
}

Mixed Mixed::operator+(const Mixed& num) const
{
	int whole = num.GetWholeNumber() + WholeNumber;
	int numerator = num.GetNumerator() + Numerator;
	int denominator = num.GetDenominator() + Denominator;
	Mixed result = Mixed(whole, numerator, denominator);
	result.TakeWholePart();
	result.Simplify();

	return result;
}

std::string Mixed::toStr() const
{
	std::stringstream sstream;
	sstream << WholeNumber << " + " << Numerator << "/" << Denominator;

	return sstream.str();
}