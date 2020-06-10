#pragma once
#include <string>
#include <iostream>

enum class GenderEnum {
	Male,
	Female
};

std::string GenderEnumToString(GenderEnum gender);

class Man
{
public:
	

	Man(std::string name, int age, GenderEnum gender, float weight);

	void SetName(std::string name);
	void SetAge(int age);
	void SetWeight(float weight);

	std::string GetName() const;
	int GetAge() const;
	float GetWeight() const;
	GenderEnum GetGender() const;
protected:
	std::string Name;
	int Age;
	GenderEnum Gender;
	float Weight;

	friend std::ostream& operator<< (std::ostream& out, const Man& man);
};

std::ostream& operator<< (std::ostream& out, const Man& man);