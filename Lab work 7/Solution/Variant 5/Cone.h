#pragma once
#include <string>
#include <iostream>

class Cone
{
protected:
	static int objectCount;
	std::string objectName;
public:
	Cone(float a, float b, float c, std::string name);

	float a;
	float b;
	float c;

	std::string GetName() const;
	std::string ToString() const;
	bool isBelongToCone(float x, float y, float z) const;
};

std::ostream& operator<< (std::ostream& out, const Cone& cone);