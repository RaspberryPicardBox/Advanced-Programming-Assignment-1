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

			while (std::getline(stringStream, word, ',')) {
				// TODO: Implement Item creation into Switch case
				switch (iterations) {

				case 0:
					attributes.push_back(word);
					break;

				case 1:
					attributes.push_back(word);
					break;

				case 2:
					attributes.push_back(word);
					break;

				case 3:
					attributes.push_back(word);
					break;

				case 4:
					if (word == "y") {
						attributes.push_back(word);
					}
					else {
						attributes.push_back("n");
					}
					break;

				case 5:
					if (word == "y") {
						attributes.push_back(word);
					}
					else {
						attributes.push_back("n");
					}
					break;

				case 6:
					if (word.length() > 0) {
						attributes.push_back(word);
					}
					break;

				case 7:
					if (word.length() > 0) {
						attributes.push_back(word);
					}
					break;
				}

				iterations++;
			}

			if (attributes[0] == "a") {
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
			
			attributes.clear();
		}
	}
}

std::string Menu :: toString() {
	std::string menu;
	int iterator = 0;

	std::cout << "----------------Appetisers----------------" << std::endl;

	for (auto& iter: this->items) {
		Item item = *iter; // TODO: Check type of item and change to type depending

		if (iterator < 3) {
			std::cout << "(" << iterator << ") " << item.name + ": " << '\x9c' << item.price << ", " << item.calories /*<< " " << item.shareable*/ << std::endl; // TODO: This piece doesn't work due to type mismatch
		}

		iterator++;
	}

	iterator = 0;

	std::cout << "----------------Main dishes----------------" << std::endl;

	for (auto& iter : this->items) {
		Item item = *iter;

		if (iterator > 2 && iterator < 7) {
			std::cout << "(" << iterator << ") " << item.name + ": " << '\x9c' << item.price << ", " << item.calories << std::endl;
		}

		iterator++;
	}

	return menu;
}