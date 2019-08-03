#include "activity.h"
#include "time.h"
#include <string>

activity::activity(std::string id, std::string new_name, time begin, time fin, std::string new_category, int length) {
	identity = id;
	name = new_name;
	start = begin;
	end = fin;
	category = new_category;
	if (length != -1)
		duration = length;

	else if (begin.get_am() == "a" && fin.get_am() == "p") {
		duration = (12 - stoi(begin.get_hour())) * 60 - stoi(begin.get_minute());
		if (fin.get_hour() == "12")
			duration += stoi(fin.get_minute());
		else
			duration += stoi(fin.get_hour()) * 60 + stoi(fin.get_minute());
	}
	else 
		duration = (stoi(end.get_hour()) - stoi(begin.get_hour())) * 60 +
		stoi(end.get_minute()) - stoi(begin.get_minute());
}

std::string activity::get_id() {
	return identity;
}

std::string activity::get_name() {
	return name;
}

std::string activity::get_category() {
	return category;
}

std::string activity::get_date() {
	return start.get_month() + "/" + start.get_day() + "/" + start.get_year();
}

int activity::get_duration() {
	return duration;
}

std::string activity::text_string() {
	std::string s;
	s = get_id() + "\n" +
		get_name() + "\n" +
		start.text_string() +
		end.text_string() +
		get_category() + "\n" +
		std::to_string(duration) + "\n";
	return s;
}

std::string activity::to_string() {
	std::string s;
	s = "Identifier: " + get_id() + "\n" +
		"Name: " + get_name() + "\n" +
		"Time started: " + start.to_string() +
		"Time ended: " + end.to_string() +
		"Category: " + get_category() + "\n" +
		"Duration: " + std::to_string(duration) + " minutes" +"\n";
	return s;
}