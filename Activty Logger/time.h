#pragma once
#include <string>
class time {
	int year;
	int month;
	int day;
	std::string hour;
	bool am;

	time(std::string new_time);	
	
	std::string to_string();

};

