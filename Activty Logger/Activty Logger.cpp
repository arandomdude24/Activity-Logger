// Activty Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "functions.h" 
#include "activity.h"
#include "time.h"
#include "Activty Logger.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

//Initalizing the global variables and global methods from "Activty Logger.h"
std::vector<activity> list = {};
std::vector<std::string> names = {};
std::vector<std::string> categories = {};

std::string names_string(std::vector<std::string> name) {
	std::string s = "Name List: \n";
	for (int i = 0; i < name.size(); i++)
		s.append(std::to_string(i + 1) + ". " + name[i] + "\n");
	return s;
}

std::string categories_string(std::vector<std::string> cat) {
	std::string s = "Category List: \n";
	for (int i = 0; i < cat.size(); i++)
		s.append(std::to_string(i + 1) + "." + cat[i] + "\n");
	return s;
}

std::string duration_string(int length) {
	std::string s;
	if (length < 60)
		s = std::to_string(length) + " minutes \n";
	else if (length < 120)
		s = std::to_string(length / 60) + " hour and " +
			std::to_string(length % 60) + " minutes \n";
	else
		s = std::to_string(length / 60) + " hours and " +
		std::to_string(length % 60) + " minutes \n";
	return s;
}

//The main method
int main()
{
	int response;
	bool close = false;

	list = {};
	names = {};
	categories = {};

	std::string line;
	std::ifstream file("list.txt");

	//This method parses the text file and stores the data into the global vectors
	if (file.is_open()) {
		std::vector<std::string> task = {};
		while (std::getline(file, line)) {
			task.push_back(line);
			if (task.size() == 10) {
				std::vector<std::string> start = { task[2], task[3], task[4] };
				std::vector<std::string> end = { task[5], task[6], task[7] };

				time begin = time(start);
				time finish = time(end);
				activity event = activity(task[0], task[1], begin, finish, task[8], stoi(task[9]));

				list.push_back(event);
				if (std::find(names.begin(), names.end(), task[1]) == names.end())
					names.push_back(task[1]);
				if (task[8] != "" && std::find(categories.begin(), categories.end(), task[8]) == categories.end())
					categories.push_back(task[8]);
				task = {};
			}
		}
		file.close();
	}

	//The while loop displays the menu options and contains methods defined in "functions.cpp"
	//The while loop only exits when the user wants to quit
	while (!close) {
		std::cout << "Choose one of the following options: \n"
			<< "1. Enter a new activity \n"
			<< "2. View data \n"
			<< "3. Reset storage \n"
			<< "4. Quit \n\n";

		std::cin >> response;

		switch (response) {
			case 1: 
				new_entry();
				break;
			case 2:
				view_data();
				break;
			case 3:
				reset();
				break;
			case 4:
				close = true;
				break;
			default:
				std::cout << "Please enter a valid number";
				break;
		}
		response = -1;
	}
}