#include "functions.h"
#include "time.h"
#include "activity.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void new_entry() {
	std::string id;
	std::string name;
	std::string date;
	std::string hour_start;
	std::string hour_end;
	std::string morning_start;
	std::string morning_end;
	
	std::cout << "Enter the identifier name: ";
	std::cin >> id;
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
	time done = time(end);
	activity event = activity(id, name, begin, done);
	std::cout << event.to_string();

	std::ofstream file("list.txt", std::fstream::app);
	if (file.is_open()) {
		file << event.text_string();
		file.close();
	}
	else
		std::cout << "This isn't working";
	
}