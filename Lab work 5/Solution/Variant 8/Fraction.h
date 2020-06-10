#pragma once
#include <iostream>

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int numerator, int denominator);

	int GetNumerator() const;
	int GetDenominator() const;

	void SetNumerator(int numerator);
	void SetDenominator(int denominator);

	void Simplify();
	float ToDecimal();

	bool operator> (Fraction fraction);
	bool operator< (Fraction fraction);
	bool operator== (Fraction fraction);
	bool operator!= (Fraction fraction);
	void operator= (Fraction fraction);

	friend Fraction operator+(Fraction fraction1, Fraction fraction2);
	friend Fraction& operator--(Fraction &fraction);
};

Fraction operator+ (Fraction fraction1, Fraction fraction2);
Fraction operator* (Fraction fraction1, Fraction fraction2);
Fraction& operator-- (Fraction &fraction);
std::ostream& operator<< (std::ostream& out, Fraction fraction);