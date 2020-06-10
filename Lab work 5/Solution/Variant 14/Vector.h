#pragma once
#include <string>

class Vector
{
private:
	float x;
	float y;
	float length;
	void calculateLength();
public:
	Vector(float x, float y);

	float getX() const;
	float getY() const;
	float getLength() const;

	void setX(float x);
	void setY(float y);

	std::string toString() const;

	float dotProduct(Vector v) const;
	float getAngle(Vector v) const;

	static float dotProduct(const Vector& v1, const Vector& v2);
	static float getAngle(const Vector& v1, const Vector& v2);

	void operator = (Vector v);
	friend Vector& operator-- (Vector& v);
};

Vector& operator-- (Vector& v);
float operator/ (Vector v1, Vector v2);
std::ostream& operator<< (std::ostream& out, const Vector& fraction);