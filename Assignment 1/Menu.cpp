#include "Menu.h"
#include <list>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

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
				Appetiser item;
				item.name = attributes[1];
				item.price = std::stof(attributes[2]);
				item.calories = std::stoi(attributes[3]);
				if (attributes[4] == "y") {
					item.shareable = true;
				}
				else {
					item.shareable = false;
				}
				if (attributes[5] == "y") {
					item.twoForOne = true;
				}
				else {
					item.twoForOne = false;
				}

				std::cout << item.toString() << std::endl;
			}
			else if (attributes[0] == "m") {
				MainCourse item;
				item.name = attributes[1];
				item.price = std::stof(attributes[2]);
				item.calories = std::stoi(attributes[3]);

				std::cout << item.toString() << std::endl;
			}
			else if (attributes[0] == "b") {
				Beverage item;
				item.name = attributes[1];
				item.price = std::stof(attributes[2]);
				item.calories = std::stoi(attributes[3]);
				item.volume = std::stoi(attributes[6]);
				item.abv = std::stof(attributes[7]);

				std::cout << item.toString() << std::endl;
			}
			
			attributes.clear();
		}
	}
}