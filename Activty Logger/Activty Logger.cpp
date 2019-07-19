// Activty Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h" 
#include "activity.h"
#include <fstream>

int main()
{
	int response;
	bool close = false;
	std::ofstream file;
	file.open("list.txt");

	while (!close) {
		std::cout << "Choose one of the following options: \n"
			<< "1. Enter a new activity \n"
			<< "2. Add a new category \n"
			<< "3. View data \n"
			<< "4. Edit data \n"
			<< "5. Reset storage \n"
			<< "6. Quit \n\n";

		std::cin >> response;

		switch (response) {
			case 1: 
				new_entry();
				break;
			case 2: 
				//new_category();
				break;
			case 3:
				//view_data();
				break;
			case 4:
				//edit_data();
				break;
			case 5:
				//reset();
				break;
			case 6:
				close = true;
				break;
			default:
				std::cout << "Please enter a valid number";
				break;
		}
		response = -1;
	}
}