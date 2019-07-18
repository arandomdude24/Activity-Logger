#include "time.h"
#include <vector>
#include <sstream>

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

std::vector<std::string> split(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}
int time::get_hour() {
	return hour;
}

int time::get_minute() {
	return minute;
}

std::string time::to_string() {
	const std::vector<std::string> months =
	{ "January", "Feburary", "March", "April", "May", "June", "July", "August", 
	"September", "October", "November", "December"};
	std::string time_output;
	time_output = 
		"The time is " + months[month - 1] + ' ' + std::to_string(day) + 
		", " + std::to_string(year) + ' ' + std::to_string(hour) 
		+ ':' + std::to_string(minute);
	if (am)
		time_output += " AM";
	else
		time_output += " PM";
	return time_output;
}