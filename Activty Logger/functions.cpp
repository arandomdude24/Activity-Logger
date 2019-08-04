#include "functions.h"
#include "time.h"
#include "activity.h"
#include "Activty Logger.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

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
	std::cout << "Enter a new activity name or a previous one from the list below\n\n" 
		<< names_string(names);
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
	std::cout << categories_string(categories);
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
		case 1: {
			std::string response;
			std::vector<activity> result = {};
			std::string output;
			std::map<std::string, int> category_map = {};
			std::map<std::string, int> event_map = {};

			std::cout << "Enter a date (mm/dd/yyyy): ";
			std::cin >> response;

			for (activity a : list) {
				if (response.compare(a.get_date()) == 0) {
					result.push_back(a);
					output.append(a.to_string() + "\n");
					category_map[a.get_category()] += a.get_duration();
					event_map[a.get_name()] += a.get_duration();
				}
			}
			if (output == "") {
				std::cout << "No results were found. Press any key to return to menu. ";
				std::cin >> response;
			}
			else {
				std::cout << "The search returned the following results: \n\n" << output << "\n";

				std::map<std::string, int>::iterator itr;
				std::cout << "Category breakdown: \n";
				for (itr = category_map.begin(); itr != category_map.end(); itr++)
					std::cout << itr->first << ": " << itr->second << " minutes \n";
				std::cout << "\nEvent breakdown: \n";
				for (itr = event_map.begin(); itr != event_map.end(); itr++)
					std::cout << itr->first << ": " << itr->second << " minutes \n";
				
				std::cout << "\nPress any key to return to the menu. ";
				std::cin >> response;
				std::cout << "\n";
			}
		}
			break;
		case 2: {
			std::string response;
			std::vector <activity> result = {};
			std::string output;
			std::map<std::string, int> category_day = {};

			std::cout << "Enter a category name from the list below \n\n";
			std::cout << categories_string(categories);
			std::cin >> response;

			if (std::find(categories.begin(), categories.end(), response) != categories.end()) {
				for (activity a : list) {
					if (response.compare(a.get_category()) == 0) {
						result.push_back(a);
						output.append(a.to_string() + "\n");
						category_day[a.get_date()] += a.get_duration();
					}
				}
				std::cout << "The search returned the following results: \n\n" << output;

				std::map<std::string, int>::iterator itr;
				std::cout << "\nCategory breakdown: \n";
				for (itr = category_day.begin(); itr != category_day.end(); itr++)
					std::cout << itr->first << ": " << itr->second << " minutes \n";
				std::cout << "\nPress any key to return the menu. "; 
				std::cin >> response; std::cout << "\n";
			}
			else {
				std::cout << "That category does not exist. Press any button to return to the menu. ";
				std::cin >> response; std::cout << "\n";
			}
			break;
		}
		case 3: {
			std::string response;
			std::vector <activity> result = {};
			std::string output;
			std::map<std::string, int> event_day = {};
			int total = 0;

			std::cout << "Enter an event name from the list below \n\n";
			std::cout << names_string(names);
			std::cin >> response;

			if (std::find(names.begin(), names.end(), response) != names.end()) {
				for (activity a : list) {
					if (response.compare(a.get_name()) == 0) {
						result.push_back(a);
						output.append(a.to_string() + "\n");
						event_day[a.get_date()] += a.get_duration();
						total += a.get_duration();
					}
				}
				std::cout << "The search returned the following results: \n\n" << output;

				std::map<std::string, int>::iterator itr;
				std::cout << "Event breakdown: \n";
				for (itr = event_day.begin(); itr != event_day.end(); itr++)
					std::cout << itr->first << ": " << itr->second << " minutes \n";
				std::cout << "\nTotal time spent: " << total << " minutes \n\n";
				std::cout << "Press any key to return the menu. ";
				std::cin >> response; std::cout << "\n";
			}
			else {
				std::cout << "That name does not exist. Press any button to return to the menu. ";
				std::cin >> response; std::cout << "\n";
			}
			break;
		}
		case 4: {
			std::string id;
			std::string output = "";

			std::cout << "Enter an ID or a partial ID: ";
			std::cin >> id;

			for (activity a : list) {
				if (a.get_id().find(id) != std::string::npos) {
					output.append(a.to_string() + "\n");
				}
			}

			if (output == "") {
				std::cout << "No results were found. Press any key to return to menu. ";
				std::cin >> id;
				std::cout << "\n";
			}
			else {
				std::cout << "The search returned the following results: \n\n" << output;
				std::cout << "Press any key to return to the menu. ";
				std::cin >> id;
				std::cout << "\n";
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