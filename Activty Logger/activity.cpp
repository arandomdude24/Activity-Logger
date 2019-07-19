#include "activity.h"
#include "time.h"
#include <string>

activity::activity(std::string new_name, time begin, time fin, std::string new_category) {
	name = new_name;
	start = begin;
	end = fin;
	category = new_category;

	duration = (end.get_hour() - begin.get_hour()) * 60 +
		end.get_minute() - begin.get_minute();
}

std::string activity::get_name() {
	return name;
}

std::string activity::get_category() {
	return category;
}

int activity::get_duration() {
	return duration;
}

std::string activity::to_string() {
	std::string s;
	s = "Name: " + get_name() + "\n" +
		"Time started: " + start.to_string() + "\n" +
		"Time ended: " + end.to_string() + "\n" +
		"Duration: " + std::to_string(duration) + " minutes \n";
	if (get_category() != "")
		s += "Category: " + get_category() + "\n";
	return s;
}