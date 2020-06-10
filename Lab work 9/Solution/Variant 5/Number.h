#pragma once
#include <string>
#include <iostream>

class Number
{
public:
	virtual std::string toStr() const = 0;
};

std::ostream& operator<< (std::ostream& out, const Number& num);