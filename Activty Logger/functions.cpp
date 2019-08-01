#include "functions.h"
#include "time.h"
#include "activity.h"
#include "Activty Logger.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void new_entry() {
	std::string id;
	std::string name;
	std::string date;
	std::string hour_start;
	std::string hour_end;
	std::string morning_start;
	std::string morning_end;
	std::string category;
	
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
	std::cout << "Enter a category name (Press N for no response): ";
	std::cin >> category;
	std::cout << "Event has been created and saved\n";

	if (category == "N")
		category = "";

	std::vector<std::string> start = { date, hour_start, morning_start };
	std::vector<std::string> end = { date, hour_end, morning_end };

	time begin = time(start);
	time done = time(end);
	activity log = activity(id, name, begin, done, category);

	list.push_back(log);
	if (std::find(names.begin(), names.end(), log.get_name()) == names.end())
		names.push_back(log.get_name());
	if (log.get_category() != "" && std::find(categories.begin(), categories.end(), log.get_category()) == categories.end())
		categories.push_back(log.get_category());

	std::ofstream file("list.txt", std::fstream::app);
	if (file.is_open()) {
		file << log.text_string();
		file.close();
	}
	else
		std::cout << "This isn't working";
}

void reset() {
	std::string response;
	std::cout << "Are you sure you want to do this? (Y or N) ";
	std::cin >> response;

	if (response == "Y") {
		std::cout << "Are you absolutely sure? This data can't be recovered. (Y or N) ";
		std::cin >> response;
		if (response == "Y") {
			std::ofstream file("list.txt", std::ofstream::out | std::ofstream::trunc);
			file.close();
			std::cout << "File erased\n";
		}
	}
}