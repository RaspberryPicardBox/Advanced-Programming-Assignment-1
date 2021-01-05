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
					}
					else if (word == "m") {
						item = new MainCourse;
					}
					else if (word == "b") {
						item = new Beverage;
					}
					//attributes.push_back(word);
					break;

				case 1:
					//attributes.push_back(word);
					(*item).name = word;
					break;

				case 2:
					//attributes.push_back(word);
					(*item).price = std::stof(word);
					break;

				case 3:
					//attributes.push_back(word);
					(*item).calories = std::stoi(word);
					break;

				case 4:
					if (word == "y") {
						//attributes.push_back(word);
						(*item).shareable = true;
					}
					else {
						//attributes.push_back("n");
						(*item).shareable = false;
					}
					break;

				case 5:
					if (word == "y") {
						//attributes.push_back(word);
						(*item).twoForOne = true;
					}
					else {
						//attributes.push_back("n");
						(*item).twoForOne = false;
					}
					break;

				case 6:
					if (word.length() > 0) {
						//attributes.push_back(word);
						(*item).volume = std::stoi(word);
					}
					else {
						(*item).volume = 0;
					}
					break;

				case 7:
					if (word.length() > 0) {
						//attributes.push_back(word);
						(*item).abv = std::stof(word);
					}
					else {
						(*item).abv = 0;
					}
					break;
				}

				iterations++;
			}

			/*if (attributes[0] == "a") {
				Appetiser *item = new Appetiser;
				(*item).name = attributes[1];
				(*item).price = std::stof(attributes[2]);
				(*item).calories = std::stoi(attributes[3]);
				if (attributes[4] == "y") {
					(*item).shareable = true;
				}
				else {
					(*item).shareable = false;
				}
				if (attributes[5] == "y") {
					(*item).twoForOne = true;
				}
				else {
					(*item).twoForOne = false;
				}

				items.push_back(item);
			}
			else if (attributes[0] == "m") {
				MainCourse *item = new MainCourse;
				(*item).name = attributes[1];
				(*item).price = std::stof(attributes[2]);
				(*item).calories = std::stoi(attributes[3]);

				items.push_back(item);
			}
			else if (attributes[0] == "b") {
				Beverage *item = new Beverage;
				(*item).name = attributes[1];
				(*item).price = std::stof(attributes[2]);
				(*item).calories = std::stoi(attributes[3]);
				(*item).volume = std::stoi(attributes[6]);
				(*item).abv = std::stof(attributes[7]);

				items.push_back(item);
			}
			
			attributes.clear();*/

			items.push_back(item);
		}
	}
}

std::string Menu :: toString() {  // TODO: Rework into a recursive-type function. Take in type, print out until done with type
	std::string menu;
	int iterator = 0;

	std::cout << "----------------Appetisers----------------" << std::endl;

	for (auto& iter: this->items) {
		Item item = *iter;

		bool shareable = item.shareable;
		bool twoForOne = item.twoForOne;

		if (iterator < 3) {

			std::cout << "(" << iterator + 1 << ") " << item.name + ": " << '\x9c' << item.price << ", " << item.calories << " cal ";

			if (shareable) {
				std::cout << "(shareable) ";
			}
			if (twoForOne) {
				std::cout << "(2-4-1) ";
			}

			std::cout << std::endl;
		}

		iterator++;
	}

	iterator = 0;

	std::cout << "----------------Main dishes----------------" << std::endl;

	for (auto& iter : this->items) {
		Item item = *iter;

		if (iterator > 2 && iterator < 7) {
			std::cout << "(" << iterator + 1 << ") " << item.name + ": " << '\x9c' << item.price << ", " << item.calories << " cal" << std::endl;
		}

		iterator++;
	}

	iterator = 0;

	std::cout << "----------------Beverages----------------" << std::endl;

	for (auto& iter : this->items) {
		Item item = *iter;

		int volume = item.volume;
		float abv = item.abv;

		if (iterator > 7 && iterator < 12) {

			std::cout << "(" << iterator + 1 << ") " << item.name + ": " << '\x9c' << item.price << ", " << item.calories << " cal ";

			if (abv > 0) {
				std::cout << "(" << volume << "ml, " << abv << "% abv)" << std::endl;
			}
			else {
				std::cout << "(" << volume << "ml)" << std::endl;
			}
		}

		iterator++;
	}

	return menu;
}