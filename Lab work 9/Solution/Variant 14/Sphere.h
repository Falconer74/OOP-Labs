#pragma once
#include "Solid.h"

class Sphere : public Solid
{
private:
	float radius;
public:
	Sphere();
	Sphere(float radius);

	float GetRadius() const;

	void SetRadius(float radius);

	virtual float GetVolume() const override;
};