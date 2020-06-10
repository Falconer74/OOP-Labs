#pragma once
#include <iostream>

class Date
{
private:
	int Year;
	int Month;
	int Day;
public:
	Date();
	Date(int year, int month, int day);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

	void SetYear(int year);
	void SetMonth(int month);
	void SetDay(int day);

	void PrintDate(std::ostream& out) const;
	~Date();
};

std::ostream& operator<<(std::ostream& out, const Date& obj);


//User deifned literal
//namespace literals {
//	unsigned long long operator "" _min(unsigned long long minutes)
//	{
//		return minutes * 60;
//	}
//}