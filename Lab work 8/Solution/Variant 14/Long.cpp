#include "Long.h"

Long::Long(float first, float second) : Pair(first, second)
{
}

Long::Long() : Pair(0, 0)
{
}

Long* Long::AddPairs(Pair p) const
{
	Long* newPair = new Long();
	newPair->SetFirst(this->first + p.GetFirst());
	newPair->SetSecond(this->second + p.GetSecond());

	return newPair;
}

Long* Long::Subtract(Pair p) const
{
	Long* newPair = new Long();
	newPair->SetFirst(this->first - p.GetFirst());
	newPair->SetSecond(this->second - p.GetSecond());

	return newPair;
}

Long* Long::Multiply(Pair p) const
{
	Long* newPair = new Long();
	newPair->SetFirst(this->first * p.GetFirst());
	newPair->SetSecond(this->second * p.GetSecond());

	return newPair;
}
