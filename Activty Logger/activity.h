#pragma once
#include "time.h"
#include <string>

class activity {
	std::string identity;
	std::string name;
	std::string category;
	time start;
	time end;
	int duration;

public:
	activity(std::string id, std::string new_name, time begin, time fin, std::string new_category="", int length=-1);

	std::string get_id();
	std::string get_name();
	std::string get_category();
	std::string get_date();
	int get_duration();
	std::string text_string();
	std::string to_string();

};