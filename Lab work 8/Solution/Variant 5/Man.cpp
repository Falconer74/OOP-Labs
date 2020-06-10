#include "Man.h"

Man::Man(std::string name, int age, GenderEnum gender, float weight) : Name(name), Age(age), Gender(gender), Weight(weight)
{
}

void Man::SetName(std::string name)
{
	Name = name;
}

void Man::SetAge(int age)
{
	Age = age;
}

void Man::SetWeight(float weight)
{
	Weight = weight;
}

std::string Man::GetName() const
{
	return Name;
}

int Man::GetAge() const
{
	return Age;
}

float Man::GetWeight() const
{
	return Weight;
}

GenderEnum Man::GetGender() const
{
	return Gender;
}

std::string GenderEnumToString(GenderEnum gender)
{
	std::string result;
	switch (gender) {
	case GenderEnum::Male:
		result = "Male";
		break;
	case GenderEnum::Female:
		result = "Female";
		break;
	}

	return result;
}

std::ostream& operator<<(std::ostream& out, const Man& man)
{
	out << "Name: " << man.Name<< "\tGender: " << GenderEnumToString(man.Gender)
		<< "\tAge: " << man.Age << "\tWeight: " << man.Weight;

	return out;
}
