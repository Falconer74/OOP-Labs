#include "Cone.h"
#include <sstream>

int Cone::objectCount = 0;

Cone::Cone(float a, float b, float c, std::string name) : a(a), b(b), c(c), objectName(name)
{
	objectCount++;
}

std::string Cone::GetName() const
{
	return objectName;
}

std::string Cone::ToString() const
{
	std::stringstream sstream;
	sstream << "x^2/" << a << "^2 = y^2/" << b << "^2 = z^2/" << c << "^2";
	return sstream.str();
}

bool Cone::isBelongToCone(float x, float y, float z) const
{
	float ratio1 = (x * x) / (a * a);
	float ratio2 = (y * y) / (b * b);
	float ratio3 = (z * z) / (c * c);

	if (ratio1 == ratio2 == ratio3) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Cone& cone)
{
	out << cone.GetName() << ":\n" << cone.ToString() << std::endl;

	return out;
}