#pragma once
#include "time.h"
#include <string>

class activity {
	std::string name;
	std::string category;
	time start;
	time end;
	int duration;

public:
	activity(std::string new_name, time begin, time fin, std::string new_category="");

	std::string get_name();
	std::string get_category();
	int get_duration();
	std::string to_string();

};