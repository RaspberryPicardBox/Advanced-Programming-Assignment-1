#include "Menu.h"
#include <list>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>

Menu :: Menu(std::string filePath) {

	std::vector<std::string> attributes;

	std::ifstream menuFile(filePath);
	std::string line;
	std::string word;

	if (menuFile.good()) {
		while (std::getline(menuFile, line)) {
			std::istringstream stringStream(line);
			
			int iterations = 0;

			Item* item = new Item;

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
					(*item).price = std::stof(word);
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
			menuList.push_back(item);
		}
		ItemList::setItems(menuList);
	}
}

std::string Menu :: toString() {  // TODO: Rework into a recursive-type function. Take in type, print out until done with type
	int iterator = 0;
	std::string menu;

	menu += "----------------Appetisers----------------\n";

	for (auto& iter: items) {
		Item item = *iter;

		bool shareable = item.shareable;
		bool twoForOne = item.twoForOne;

		if (item.type == "a") {

			menu += "(" + std::to_string(iterator + 1) + ") " + item.name + ": " + '\x9c' + std::to_string(item.price) + ", " + std::to_string(item.calories) + " cal ";

			if (shareable) {
				menu += "(shareable) ";
			}
			if (twoForOne) {
				menu += "(2-4-1) ";
			}

			menu += "\n";
		}

		iterator++;
	}

	iterator = 0;

	menu += "----------------Main dishes----------------\n";

	for (auto& iter : items) {
		Item item = *iter;

		if (item.type == "m") {
			menu += "(" + std::to_string(iterator + 1) + ") " + item.name + ": " + '\x9c' + std::to_string(item.price) + ", " + std::to_string(item.calories) + " cal\n";
		}

		iterator++;
	}

	iterator = 0;

	menu += "----------------Beverages----------------\n";

	for (auto& iter : items) {
		Item item = *iter;

		int volume = item.volume;
		float abv = item.abv;

		if (item.type == "b") {

			menu += "(" + std::to_string(iterator + 1) + ") " + item.name + ": " + '\x9c' + std::to_string(item.price) + ", " + std::to_string(item.calories) + " cal ";

			if (abv > 0) {
				menu += "(" + std::to_string(volume) + "ml, " + std::to_string(abv) + "% abv)\n";
			}
			else {
				menu += "(" + std::to_string(volume) + "ml)\n";
			}
		}

		iterator++;
	}
	return menu;
}