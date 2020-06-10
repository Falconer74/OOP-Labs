#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"
#include <sstream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <iostream>

Logger* Logger::instance = nullptr;

Logger::Logger() {

}

Logger& Logger::GetInstance()
{
	if (instance == nullptr) {
		instance = new Logger();
	}

	return *instance;
}

void Logger::AddRecord(Triangle triangle)
{
	auto timePoint = std::chrono::system_clock::now();
	time_t ticks = std::chrono::system_clock::to_time_t(timePoint);
	//gmtime() - not thread safe, gmtime_s() - thread safe, but not cross-platform
	//No need to free memory
	tm t = *gmtime(&ticks);

	std::stringstream sstr;
	//std::put_time https://en.cppreference.com/w/cpp/io/manip/put_time
	sstr << "Object name: " << triangle.GetObjectName() << "\n\tTime: " << std::put_time(&t, "%y:%m:%d %T")
		<< "\n\tPerimeter: " << triangle.GetPerimeter() << "\n\tArea: " << triangle.GetArea();

	logs.push_back(sstr.str());
}

void Logger::SaveLogs()
{
	std::ofstream fout(FILE_NAME);

	if (!fout.is_open()) {
		std::cout << "File " << FILE_NAME << " can not be opened" << std::endl;

		return;
	}

	for (int i = 0; i < logs.size(); ++i) {
		fout << logs[i] << std::endl;
	}

	fout.close();
}