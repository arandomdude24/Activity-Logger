#pragma once
#include <string>
#include <vector>

class time {
	int month;
	int day;
	int year;
	int hour;
	int minute;
	bool am;

public:
	time();
	time(std::vector<std::string> new_time);

	int get_hour();
	int get_minute();
	std::string to_string();

private:
	std::vector<std::string> split(const std::string& s, char delim);
};