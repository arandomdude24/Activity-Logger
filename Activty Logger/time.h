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

	std::string get_month();
	std::string get_day();
	std::string get_year();
	std::string get_hour();
	std::string get_minute();
	std::string get_am();
	std::string text_string();
	std::string to_string();

private:
	std::vector<std::string> split(const std::string& s, char delim);
};