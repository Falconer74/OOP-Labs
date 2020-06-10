#pragma once
class Vector
{
private:
	float x;
	float y;
	float length;
	void calculateLength();
public:
	Vector();
	Vector(float x, float y);

	
	float getX() const;
	float getY() const;
	float getLength() const;

	void setX(float x);
	void setY(float y);

	void print();

	float dotProduct(Vector v) const;
	float getAngle(Vector v) const;

	static float dotProduct(const Vector& v1, const Vector& v2);
	static float getAngle(const Vector& v1, const Vector& v2);

	~Vector();
};