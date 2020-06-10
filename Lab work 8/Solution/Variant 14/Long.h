#pragma once
#include "Pair.h"

class Long : public Pair
{
public:
	Long(float first, float second);
	Long();

	Long* AddPairs(Pair p) const override;
	Long* Subtract(Pair p) const;
	Long* Multiply(Pair p) const;
};