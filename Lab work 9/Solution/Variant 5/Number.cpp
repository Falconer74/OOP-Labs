#include "Number.h"

std::ostream& operator<<(std::ostream& out, const Number& num)
{
	out << num.toStr();

	return out;
}
