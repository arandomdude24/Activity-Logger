#pragma once
#include <string>
#include <vector>

class time {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	bool am;

	time(std::vector<std::string> new_time);

public:
	int get_hour();
	int get_minute();
	std::string to_string();
};