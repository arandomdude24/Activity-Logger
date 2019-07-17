// Activty Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h" 

int main()
{
	int response;
	bool close = false;
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
