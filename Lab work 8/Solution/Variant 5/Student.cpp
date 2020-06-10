#include "Student.h"

Student::Student(std::string name, int age, GenderEnum gender, float weight, int course) : Man(name, age, gender, weight), Course(course)
{
}

int Student::GetCourse() const
{
	return Course;
}

void Student::SetCourse(int course)
{
	Course = course;
}

void Student::NextCourse()
{
	Course++;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << (Man&)student << "\tCourse:" << student.Course;

	return out;
}
