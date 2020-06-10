#pragma once

#include <string>
#include <vector>
#include "Cone.h"
#define FILE_NAME "logs.txt"

class Logger
{
private:
	static Logger* instance;
	std::vector<std::string> logs;

	Logger();
public:
	static Logger& GetInstance();
	void AddRecord(Cone cone);
	void SaveLogs();
};