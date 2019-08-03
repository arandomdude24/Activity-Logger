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
	std::cout << "Enter a new activity name or a previous one from the list below\n\n" <<
		"Name List:\n" << names_string(names) << "\n";
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

	std::cout << "Enter a new category name or a previous one from the list below\n";
	std::cout << "Press N for no response\n\n";
	std::cout << "Category List:\n" << categories_string(categories) << "\n";
	std::cin >> category;

	std::cout << "Event has been created and saved\n\n";

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

void view_data() {
	std::string response = "";
	std::cout << "View data by: \n"
		<< "1. Day \n"
		<< "2. Category Name \n"
		<< "3. Activity Name \n"
		<< "4. Unique Name \n";
	std::cin >> response;

	switch (stoi(response)) {
		case 1:
			//by_date();
			break;
		case 2:
			//by_category();
			break;
		case 3:
			//by_activity();
			break;
		case 4: {
			std::string id;
			std::vector<activity> result = {};
			std::string restart;

			std::cout << "Enter an ID or a partial ID: ";
			std::cin >> id;

			for (activity a : list) {
				if (a.get_id().find(id) != std::string::npos)
					result.push_back(a);
			}

			if (result.size() == 0) {
				std::cout << "No results were found. Press any key to return to menu. ";
				std::cin >> restart;
			}
			else {
				std::cout << "The search returned the following results: \n";
				for (activity a : result)
					std::cout << a.to_string() << "\n";
				std::cout << "Press any key to return to the menu. ";
				std::cin >> restart;
			}
			break;
		}
		default:
			std::cout << "Please enter a valid number";
			break;
	}
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