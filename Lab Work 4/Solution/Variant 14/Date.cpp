#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
#include <chrono>
#include <ctime>

Date::Date()
{
	auto timePoint = std::chrono::system_clock::now();
	time_t ticks = std::chrono::system_clock::to_time_t(timePoint);
	//gmtime() - not thread safe, gmtime_s() - thread safe, but not cross-platform
	//No need to free memory
	tm t = *gmtime(&ticks);
	Year = t.tm_year + 1900; //Because tm_year starts from 1900
	Month = t.tm_mon + 1; //Because tm_mon starts from 0
	Day = t.tm_mday;
}

Date::Date(int year, int month, int day) : Year(year), Month(month), Day(day)
{

}

int Date::GetYear() const
{
	return Year;
}

int Date::GetMonth() const
{
	return Month;
}

int Date::GetDay() const
{
	return Day;
}

void Date::SetYear(int year)
{
	Year = year;
}

void Date::SetMonth(int month)
{
	Month = month;
}

void Date::SetDay(int day)
{
	Day = day;
}

void Date::PrintDate(std::ostream& out) const
{
	out << Year << "." << Month << "." << Day << std::endl;
}

Date::~Date()
{
	std::cout << "Destructor has been invoked" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Date& obj)
{
	obj.PrintDate(out);
	return out;
}