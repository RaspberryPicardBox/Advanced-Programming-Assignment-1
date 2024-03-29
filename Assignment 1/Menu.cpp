#include "Menu.h"
#include <list>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <iomanip>

Menu :: Menu(std::string filePath) { // O(n^2)

	std::vector<std::string> attributes;

	std::ifstream menuFile(filePath);
	std::string line;
	std::string word;

	if (menuFile.good()) {
		while (std::getline(menuFile, line)) {
			std::istringstream stringStream(line);
			
			int iterations = 0; // Iterations keeps track of which column we're in

			Item* item{};

			while (std::getline(stringStream, word, ',')) {

				switch (iterations) {

				case 0:
					if (word == "a") {
						item = new Appetiser;
						(*item).type = word;
					}
					else if (word == "m") {
						item = new MainCourse;
						(*item).type = word;
					}
					else if (word == "b") {
						item = new Beverage;
						(*item).type = word;
					}
					break;

				case 1:
					(*item).name = word;
					break;

				case 2:
					(*item).price = stod(word);
					break;

				case 3:
					(*item).calories = std::stoi(word);
					break;

				case 4:
					if (word == "y") {
						(*item).shareable = true;
					}
					else {
						(*item).shareable = false;
					}
					break;

				case 5:
					if (word == "y") {
						(*item).twoForOne = true;
					}
					else {
						(*item).twoForOne = false;
					}
					break;

				case 6:
					if (word.length() > 0) {
						(*item).volume = std::stoi(word);
					}
					else {
						(*item).volume = 0;
					}
					break;

				case 7:
					if (word.length() > 0) {
						(*item).abv = std::stof(word);
					}
					else {
						(*item).abv = 0;
					}
					break;
				}
				iterations++;
			}
			items.push_back(item);
		}
	}
}

// O(n)
std::string Menu :: toString() { // TODO: Add commands to sort the menu by item price
	int iterator = 0;
	std::string menu;

	menu += "----------------Appetisers----------------\n";

	for (std::vector<Item*>::iterator menuIt = items.begin(); menuIt != items.end(); ++menuIt) {
		Item (*item) = *menuIt;

		iterator++;

		if ((*item).type == "a") {
			menu += "(" + std::to_string(iterator) + ") " + (*item).toString();
			if ((*item).shareable == true) {
				menu += "(shareable) ";
			}
			if ((*item).twoForOne == true) {
				menu += "(2-4-1) ";
			}
			menu += "\n";
		}
	}

	iterator = 0;

	menu += "----------------Main dishes----------------\n";

	for (std::vector<Item*>::iterator menuIt = items.begin(); menuIt != items.end(); ++menuIt) {
		Item(*item) = *menuIt;

		iterator++;

		if ((*item).type == "m") {
			menu += "(" + std::to_string(iterator) + ") " + (*item).toString() + "\n";
		}
	}

	iterator = 0;

	menu += "----------------Beverages----------------\n";

	for (std::vector<Item*>::iterator menuIt = items.begin(); menuIt != items.end(); ++menuIt) {
		Item(*item) = *menuIt;

		iterator++;

		int volume = (*item).volume;
		float abv = (*item).abv;

		if ((*item).type == "b") {

			menu += "(" + std::to_string(iterator) + ") " + (*item).toString();

			if (abv == 0) {
				menu += "(" + std::to_string((*item).volume) + "ml)\n";
			}
			else {
				std::stringstream abvFixed; // Setting the precision of abv to remove 0s
				abvFixed.precision(3);
				abvFixed << (*item).abv;
				menu += "(" + std::to_string((*item).volume) + "ml, " + abvFixed.str() + "% abv)\n";
			}
		}
	}
	return menu;
}