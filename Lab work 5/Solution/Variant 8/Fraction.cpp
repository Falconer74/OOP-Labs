#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}

int Fraction::GetNumerator() const
{
	return numerator;
}

int Fraction::GetDenominator() const
{
	return denominator;
}

void Fraction::SetNumerator(int numerator)
{
	this->numerator = numerator;
}

void Fraction::SetDenominator(int denominator)
{
	this->denominator = denominator;
}

void Fraction::Simplify()
{
	bool isSimplified = false;
	while (!isSimplified) {
		int min;
		if (numerator < denominator)
			min = numerator;
		else
			min = denominator;

		for (int i = 2; i <= min; ++i) {
			if (numerator % i == 0 && denominator % i == 0) {
				numerator /= i;
				denominator /= i;
				break;
			}
			isSimplified = true;
		}
	}
}

float Fraction::ToDecimal()
{
	return numerator / denominator;
}

bool Fraction::operator>(Fraction fraction)
{
	int commonDenominator = denominator * fraction.denominator;
	int firstNumerator = numerator * fraction.denominator;
	int secondNumerator = fraction.numerator * denominator;

	return firstNumerator > secondNumerator;
}

bool Fraction::operator<(Fraction fraction)
{
	int commonDenominator = denominator * fraction.denominator;
	int firstNumerator = numerator * fraction.denominator;
	int secondNumerator = fraction.numerator * denominator;

	return secondNumerator > firstNumerator;
}

bool Fraction::operator==(Fraction fraction)
{
	int commonDenominator = denominator * fraction.denominator;
	int firstNumerator = numerator * fraction.denominator;
	int secondNumerator = fraction.numerator * denominator;

	return secondNumerator == firstNumerator;
}

bool Fraction::operator!=(Fraction fraction)
{
	int commonDenominator = denominator * fraction.denominator;
	int firstNumerator = numerator * fraction.denominator;
	int secondNumerator = fraction.numerator * denominator;

	return !(secondNumerator == firstNumerator);
}

void Fraction::operator=(Fraction fraction)
{
	numerator = fraction.numerator;
	denominator = fraction.denominator;
}

Fraction operator+(Fraction fraction1, Fraction fraction2)
{
	int denominator = fraction1.denominator * fraction2.denominator;
	int numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
	Fraction fraction(numerator, denominator);
	fraction.Simplify();

	return fraction;
}

Fraction operator*(Fraction fraction1, Fraction fraction2)
{
	int numerator = fraction1.GetNumerator() * fraction2.GetNumerator();
	int denominator = fraction1.GetDenominator() * fraction2.GetDenominator();
	Fraction fraction(numerator, denominator);
	fraction.Simplify();

	return fraction;
}

Fraction& operator--(Fraction &fraction)
{
	fraction.numerator -= fraction.denominator;
	return fraction;
}

std::ostream& operator<<(std::ostream& out, Fraction fraction)
{
	out << fraction.GetNumerator() << "/" << fraction.GetDenominator();

	return out;
}