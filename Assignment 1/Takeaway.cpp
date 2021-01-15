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
#include <iomanip>
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
			for (int i = 1; i < parameters.size(); i++) {
				int userChoice = std::stoi(parameters[i]);

				if (userChoice <= menu.items.size()) {
					Item* choice = menu.items[userChoice - 1];
					order.add(choice);
				}
				else {
					std::cout << "Sorry, but that item is unavailable." << std::endl;
				}
			}
		}
		else if (command.compare("remove") == 0)
		{
			for (int i = 1; i < parameters.size(); i++) {
				int userChoice = std::stoi(parameters[i]);

				if (userChoice <= order.items.size()) {
					Item* choice = order.items[userChoice - 1];
					order.remove(choice);
				}
				else {
					std::cout << "Sorry, but that item is unavailable." << std::endl;
				}
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

			// Re-getting user input here for confirmation without leaving the checkout command
			// Would be better in a function, but would require changing this file
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

			string command = parameters[1];

			if (command == "y") {
				order.printReceipt();
			}

		}
		else if (command.compare("help") == 0)
		{
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << "A takeaway console application for ordering, checking out, and getting a receipt for food." << std::endl << std::endl;
			std::cout << "Commands:" << std::endl;
			std::cout << "menu    Displays the menu." << std::endl;
			std::cout << "add [menuNumber]    Adds an item from the menu to your order based on it's number." << std::endl;
			std::cout << "remove [menuNumber]    Removes an item from your order based on it's menu number." << std::endl;
			std::cout << "checkout [y/n]   Shows a summary of your order, and asks to print out the receipt or not." << std::endl;
			std::cout << "exit   Shuts down the program." << std::endl;
			std::cout << "----------------------------------------------------------" << std::endl;
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();

}