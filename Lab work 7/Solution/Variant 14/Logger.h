#pragma once

#include <string>
#include <vector>
#include "Triangle.h"
#define FILE_NAME "logs.txt"

class Logger
{
private:
	static Logger* instance;
	std::vector<std::string> logs;

	Logger();
public:
	static Logger& GetInstance();
	void AddRecord(Triangle triangle);
	void SaveLogs();
};