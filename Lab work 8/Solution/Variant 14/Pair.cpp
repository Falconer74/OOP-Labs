#include "Pair.h"

Pair::Pair()
{
	this->first = 0;
	this->second = 0;
}

Pair::Pair(int first, int second)
{
	this->first = first;
	this->second = second;
}

int Pair::GetFirst() const
{
	return first;
}

int Pair::GetSecond() const
{
	return second;
}

void Pair::SetFirst(int first)
{
	this->first = first;
}

void Pair::SetSecond(int second)
{
	this->second = second;
}

Pair* Pair::AddPairs(Pair p) const
{
	Pair* newPair = new Pair();
	newPair->SetFirst(this->first + this->second);
	newPair->SetSecond(p.GetFirst() + p.GetSecond());

	return newPair;
}

std::ostream& operator<<(std::ostream& out, const Pair& p)
{
	out << "( " << p.first << " ; " << p.second << " )";

	return out;
}
