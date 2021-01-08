/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			int userChoice = std::stoi(parameters[1]);

			if (userChoice <= menu.menuList.size()) {
				Item* choice = menu.menuList[userChoice - 1];
				order.add(choice);
			}
			else {
				std::cout << "Sorry, but that item is unavailable." << std::endl;
			}



			// You may also wish to implement the ability to add multiple items at once!
			// e.g. add 1 5 9 
		}
		else if (command.compare("remove") == 0)
		{
			int userChoice = std::stoi(parameters[1]);

			if (userChoice <= menu.menuList.size()) {
				Item* choice = menu.menuList[userChoice - 1];
				order.remove(choice);
			}
			else {
				std::cout << "Sorry, but that item is unavailable." << std::endl;
			}
			
		}
		else if (command.compare("checkout") == 0)
		{
			std::cout << order.toString() << std::endl;

			if (order.twoForOneFlag == true) {
				std::cout << "2-4-1 discount applied! Savings: \x9c" + std::to_string(order.twoForOneTotal) + "\n" << std::endl;
			}

			std::cout << "Total: \x9c" + std::to_string(order.total) + "\n" << std::endl;

			std::cout << "Do you want to confirm your oder?\nType 'y' to confirm, or 'n' to go back and modify it." << std::endl;

			getline(cin, userCommand);
			char* cstr = new char[userCommand.length() + 1];
			strcpy(cstr, userCommand.c_str());

			char* token;
			token = strtok(cstr, " ");

			while (token != NULL)
			{
				parameters.push_back(token);
				token = strtok(NULL, " ");
			}

			string command = parameters[0];

			if (command == "y") {
				order.printReceipt();
			}

		}
		else if (command.compare("help") == 0)
		{
			
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();

}