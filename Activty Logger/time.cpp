#include "time.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

time::time() {}

time::time(std::vector<std::string> new_time) {
	std::vector<std::string> date = split(new_time[0], '/');
	std::vector<std::string> local = split(new_time[1], ':');

	month = stoi(date[0]);
	day = stoi(date[1]);
	year = stoi(date[2]);
	hour = stoi(local[0]);
	minute = stoi(local[1]);

	if (new_time[2] == "a")
		am = true;
	else
		am = false;
}

std::vector<std::string> time::split(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

std::string time::get_month() {
	std::string mon = std::to_string(month);
	if (month < 10)
		mon.insert(0, 1, '0');
	return mon;
}

std::string time::get_day() {
	std::string today = std::to_string(day);
	if (day < 10)
		today.insert(0, 1, '0');
	return today;
}

std::string time::get_year() {
	return std::to_string(year);
}

std::string time::get_hour() {
	return std::to_string(hour);
}

std::string time::get_minute() {
	std::string min = std::to_string(minute);
	if (minute < 10)
		min.insert(0, 1, '0');
	return min;
}

std::string time::get_am() {
	if (am)
		return "a";
	else
		return "p";
}

std::string time::text_string() {
	std::string s;
	s = get_month() + "/" + get_day() + "/" + get_year() + "\n" +
		get_hour() + ":" + get_minute() + "\n" +
		get_am() + "\n";
	return s;
}

std::string time::to_string() {
	const std::vector<std::string> months =
	{ "January", "Feburary", "March", "April", "May", "June", "July", "August", 
	"September", "October", "November", "December"};
	std::string time_output;
	
	time_output = 
		months[month - 1] + ' ' + get_day() + 
		", " + get_year() + ' ' + get_hour() 
		+ ':' + get_minute();
	if (am)
		time_output += " AM";
	else
		time_output += " PM\n";
	return time_output;
}