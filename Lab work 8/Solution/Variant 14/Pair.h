#pragma once
#include <iostream>

class Pair
{
protected:
	int first;
	int second;
public:
	Pair();
	Pair(int first, int second);

	int GetFirst() const;
	int GetSecond() const;

	void SetFirst(int first);
	void SetSecond(int second);

	virtual Pair* AddPairs(Pair p) const;

	friend std::ostream& operator<< (std::ostream& out, const Pair& p);
};

std::ostream& operator<< (std::ostream& out, const Pair& p);