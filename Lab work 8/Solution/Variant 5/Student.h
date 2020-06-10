#pragma once
#include "Man.h"

class Student : public Man
{
protected:
	int Course;
public:
	Student(std::string name, int age, GenderEnum gender, float weight, int course);

	int GetCourse() const;
	void SetCourse(int course);

	void NextCourse();

	friend std::ostream& operator<< (std::ostream& out, const Student& student);
};

std::ostream& operator<< (std::ostream& out, const Student& student);