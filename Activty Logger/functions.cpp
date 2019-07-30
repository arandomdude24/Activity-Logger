#include "functions.h"
#include "time.h"
#include "activity.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void new_entry() {
	std::string name;
	std::string date;
	std::string hour_start;
	std::string hour_end;
	std::string morning_start;
	std::string morning_end;
	
	std::cout << "Enter the activity name: ";
	std::cin >> name; 
	std::cout << "Enter the date in the following format mm/dd/yyyy: ";
	std::cin >> date;
	std::cout << "Enter the time the activity began in the following format hh:mm ";
	std::cin >> hour_start;
	std::cout << "Enter a for AM and p for PM: ";
	std::cin >> morning_start;
	std::cout << "Enter the time the activty ended in the following format hh:mm ";
	std::cin >> hour_end;
	std::cout << "Enter a for AM and p for PM: ";
	std::cin >> morning_end;

	std::vector<std::string> start = { date, hour_start, morning_start };
	std::vector<std::string> end = { date, hour_end, morning_end };

	
	time begin = time(start);
	std::cout << "Start time: " << begin.to_string();
	time done = time(end);
	std::cout << "End time: " << done.to_string();
	activity event = activity(name, begin, done);
	std::cout << event.to_string();
	
}