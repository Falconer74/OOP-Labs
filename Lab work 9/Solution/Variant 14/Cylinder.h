#pragma once
#include "Solid.h"

class Cylinder : public Solid
{
private:
	float height;
	float baseRadius;
public:
	Cylinder();
	Cylinder(float height, float radius);

	float GetHeight() const;
	float GetBaseRadius() const;

	void SetHeight(float height);
	void SetBaseRadius(float radius);

	// Inherited via Solid
	virtual float GetVolume() const override;
};

